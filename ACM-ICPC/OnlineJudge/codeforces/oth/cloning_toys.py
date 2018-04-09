m, n = map(int, input().split())

clo = n - 1
lea = m - clo

if n <= 0:
    print('No')
elif lea < 0:
    print('No')
elif n == 1 and lea != 0:
    print('No')
elif lea % 2 != 0:
    print('No')
else:
    print('Yes')
