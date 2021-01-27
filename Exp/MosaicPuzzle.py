#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
用图库中的图拼成目标图片

图片特征值用的图片平均值
"""


import numpy, os
from PIL import Image


# 目标图片路径
target      = './Pictures/WallP/P001.png'
result_path = './res.jpg'

# 图库路径
img_path = './Pictures/pic/pho'
img_cnt  = 200
# 拼图时图库中图片的大小
ps = 40

# 目标图片缩放级别
scale = 10

cache = {}


def load_image(pic_path):
    if cache.get(pic_path) is not None:
        return cache[pic_path]

    x = Image.open(pic_path)
    w, h = x.size
    x = x.crop((0, 0, min(w, h), min(w, h)))
    x = x.resize((ps, ps))

    cache[pic_path] = x
    return x


def image_mean(pic_path: str):
    img = numpy.array(load_image(pic_path))
    res = img.mean(axis=1).mean(axis=0)
    return res


def find_cloest_image(pixel, l):
    import random

    def MSE(p0, p1):
        return ((p0 - p1) ** 2).sum()

    res = None
    cmp = 2560000

    for i, j in l:
        loss = MSE(j, pixel)

        if loss < cmp:
            if random.randint(0, 10) <= 2 and res is not None:
                continue
            res = i
            cmp = loss
    return res


pics = list(map(lambda x: img_path + '/' + x, os.listdir(img_path)[:img_cnt]))
pic_mean = list(map(image_mean, pics))
pic_mean = tuple(zip(pics, pic_mean))


target = Image.open(target)
tw, th = target.size
tw //= scale
th //= scale
target = target.resize((tw, th))
target = numpy.array(target)

s_i, s_j, _ = target.shape
res = []


for i in range(s_i):
    res.append([])
    for j in range(s_j):
        pic = find_cloest_image(target[i][j], pic_mean)
        res[-1].append(pic)


new_im = Image.new('RGB', (tw * ps, th * ps))

idx_r = 0
for i in range(len(res)):
    idx_c = 0
    for img in res[i]:
        new_im.paste(load_image(img), (idx_c, idx_r))
        idx_c += ps
    idx_r += ps


new_im.save(result_path)

