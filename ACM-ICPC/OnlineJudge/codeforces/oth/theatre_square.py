def fun(l, a):
    if l % a == 0:
        return int(l / a)
    else:
        return int(l / a) + 1


n, m, a = map(int, input().split())
print(str(fun(n, a) * fun(m, a)))
