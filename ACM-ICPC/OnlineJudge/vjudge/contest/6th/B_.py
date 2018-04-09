n, limit = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
amount = sum(data)

L, R = 0, 0
if amount % n == 0:
    L = R = int(amount / n)
else:
    L = int(amount / n)
    R = L + 1
l, r = R, 2 * 10 ** 9
while l <= r:
    mid = int((l + r) / 2)
    cnt = 0
    for it in data[::-1]:
        if it > mid:
            cnt += it - mid
        else:
            break

    if cnt > limit:
        l = mid + 1
    elif cnt <= limit:
        R = mid
        r = mid - 1

    cnt = 0

l, r = 0, L
while l <= r:
    mid = int((l + r) / 2)
    cnt = 0
    for it in data:
        if it < mid:
            cnt += mid - it
        else:
            break

    if cnt <= limit:
        L = mid
        l = mid + 1
    elif cnt > limit:
        r = mid - 1

    cnt = 0

print(str(R - L))
