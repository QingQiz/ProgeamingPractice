#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
用图库中的图拼成目标图片
"""


import os
import PIL
import rich
import argh
import numpy
from PIL import Image
from rich.console import Console
from rich.progress import Progress


class ImageLoader:
    def __init__(self, logger, **kwargs):
        self._cache = {}
        self._feature = {}
        self._kwargs = kwargs
        self._logger = logger

    def loadImg(self, path, crop=True, zoom=False):
        if (res := self._cache.get(path)) is not None:
            return res

        try:
            # self._logger(f'Loading {path}')

            img = Image.open(path)
            w, h = img.size

            if zoom:
                w //= self._kwargs['zoom']
                h //= self._kwargs['zoom']
                img = img.resize((w, h))
            if crop:
                size = min(w, h, self._kwargs['size'])
                img = img.crop((0, 0, size, size))
                img = img.resize((size, size))

            self._cache[path] = img
            return img
        except OSError as e:
            self._logger('[red][b]' + str(e).strip())
            exit(-1)

    def imgFeature(self, path):
        if (res := self._feature.get(path)) is not None:
            return res

        # self._logger(f'Calculating the feature of image {path}')
        img = self.loadImg(path)
        img = numpy.array(img)
        feature = img.mean(axis=1).mean(axis=0)
        self._feature[path] = feature
        return feature

    def cloestImage(self, pixel):
        def MSE(p1, p2):
            return ((p1 - p2) ** 2).sum()

        # self._logger(f'Finding cloest image for pixel {pixel}')

        res = None
        cmp = 2560000

        for img in self._cache:
            if img == self._kwargs['target']:
                continue

            feature = self.imgFeature(img)

            loss = MSE(feature, pixel)

            if loss < cmp :
                res = img
                cmp = loss
        return res


def run(**kwargs):
    target      = kwargs['target']
    output      = kwargs['output']
    dataset     = kwargs['dataset']
    dataset_cnt = kwargs['img_cnt']
    size        = kwargs['size']

    with Progress() as prog:
        logger = prog.console.print
        dataLoader = ImageLoader(logger, **kwargs)

        imgs = os.listdir(dataset)[:dataset_cnt]

        task_load_image = prog.add_task(f'Loading images [000/{dataset_cnt}]', total=dataset_cnt)

        cnt = 1
        for i in imgs:
            dataLoader.loadImg(f'{dataset}/{i}')
            prog.update(task_load_image, advance=1, description=f'Loading images [{cnt:0>3}/{dataset_cnt}]')
            cnt += 1

        task_calc_feature = prog.add_task(f'Calculating image feature [000/{dataset_cnt}]', total=dataset_cnt)

        cnt = 1
        for i in imgs:
            dataLoader.imgFeature(f'{dataset}/{i}')
            prog.update(task_calc_feature, advance=1, description=f'Calculating image feature [{cnt:0>3}/{dataset_cnt}]')
            cnt += 1

        logger(f'[green]Loading target image...')
        target_img = dataLoader.loadImg(target, crop=False, zoom=True)
        target_img = numpy.array(target_img)

        shape = target_img.shape
        logger(f'[green]The shape of target image is [/green]{shape}')

        task_find_cloest = prog.add_task(f'Finding cloest image [00000/{shape[0] * shape[1]}]', total=shape[0] * shape[1])

        cloest_image = []
        cnt = 1
        for i in range(shape[0]):
            cloest_image.append([])
            for j in range(shape[1]):
                img = dataLoader.cloestImage(target_img[i][j])
                cloest_image[-1].append(img)
                prog.update(task_find_cloest, advance=1, description=f'Finding cloest image [{cnt:0>6}/{shape[0] * shape[1]:0>6}]')
                cnt += 1

        task_paste_image = prog.add_task(f'Pasting image [00000/{shape[0] * shape[1]}]', total=shape[0] * shape[1])

        logger(f'[green]Creating new image, size: {(shape[0] * size, shape[1] * size)}')

        img_res = Image.new('RGB', (shape[1] * size, shape[0] * size))

        cnt = 1
        for i in range(shape[0]):
            for j in range(shape[1]):
                # logger(f'Pasting image {cloest_image[i][j]} to {(i * size, j * size)}')
                img_res.paste(dataLoader.loadImg(cloest_image[i][j]), (j * size, i * size))
                prog.update(task_paste_image, advance=1, description=f'Pasting image [{cnt:0>6}/{shape[0] * shape[1]:0>6}]')
                cnt += 1

        logger(f'[green]Saving image to {output}')
        img_res.save(output)


if __name__ == "__main__":
    parser = argh.ArghParser()
    parser.add_argument('-t', '--target', required=True, help='target image')
    parser.add_argument('-o', '--output', required=True, help='output')
    parser.add_argument('-d', '--dataset', required=True, help='dataset path')
    parser.add_argument('-n', '--img-cnt', required=False, default=100, type=int, help='the count of images to use in dataset')
    parser.add_argument('-s', '--size', required=False, default=30, type=int, help='the size of images in dataset')
    parser.add_argument('-z', '--zoom', required=False, default=10, type=int, help='zoom of target image')

    parser.set_default_command(run)

    parser.dispatch()
