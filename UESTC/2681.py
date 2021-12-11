import math
n, C = map(int, input().split())
d = list(map(int, input().split()))
p, q = ((n - 1) * C, n * 2) if 0 in d else (C, 2)
g = math.gcd(p, q)
print('%d/%d' % (p // g, q // g))
