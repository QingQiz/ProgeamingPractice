#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import networkx
import copy


def HITS(g):
    x = {j:[i[0] for i in g.edges if i[1] == j] for j in g.nodes}
    y = {j:[i[1] for i in g.edges if i[0] == j] for j in g.nodes}

    def do():
        val = {i:[1, 1] for i in g.nodes}
        while True:
            val2 = copy.deepcopy(val)

            for i in g.nodes:
                sum_hub = 0
                for j in x[i]:
                    sum_hub += val[j][1]
                val2[i][0] = sum_hub

                sum_auth = 0
                for j in y[i]:
                    sum_auth += val[j][0]
                val2[i][1] = sum_auth

            sum_auth = sum([val2[i][0] for i in val2])
            sum_hub  = sum([val2[i][1] for i in val2])
            val2 = {i:[val2[i][0]/sum_auth, val2[i][1]/sum_hub] for i in val2}
            val = val2
            yield val2

    iterator = do()
    def get_next():
        return next(iterator)
    return get_next


def out(val):
    for i in sorted(val):
        print(f'{i}: auth: {val[i][0]:.2f}, hub: {val[i][1]:.2f}')


def build_graph():
    edges = [['D','A'], ['E','B'], ['F','C'], ['G', 'C'], ['H','C'],['E','C']]

    g = networkx.DiGraph()
    for e in edges:
        g.add_edge(e[0], e[1])
    return g


if __name__ == '__main__':
    hits = HITS(build_graph())

    hits()
    out(hits())

