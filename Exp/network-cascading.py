#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import networkx as nx
import copy

g = nx.Graph()

edges = ['cd', 'ce', 'cf', 'df', 'dg', 'ef', 'eh', 'ei', 'fi', 'fj', 'gj', 'gk', 'hi', 'jk']

for i in edges:
    g.add_edge(i[0], i[1])

sig = {i:'b' for i in g.nodes}
sig['c'] = 'a'
sig['d'] = 'a'

# g.add_edge('c', 'j')

q = 2/5

x = 1
while True:
    b = True
    print(f'STEP {x}:')

    sig_ = copy.deepcopy(sig)

    for i in g.nodes:
        if sig[i] == 'a':
            continue
        n = list(g.neighbors(i))
        new = [node for node in n if sig[node] == 'a']
        cnt = len(new)
        q_ = cnt / len(n)
        if q_ >= q:
            sig_[i] = 'a'
            print(f'\t{i}: {cnt} of {len(n)} use A')
            b = False
    sig = sig_
    x += 1
    if b:
        break

