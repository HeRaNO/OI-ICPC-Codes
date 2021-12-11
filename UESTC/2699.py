from functools import cmp_to_key
n = int(input())
A = []
ONE = 10 ** 7
for i in range(n):
	a, p = input().split()
	a = int(a)
	x, y = p.split('.')
	p = int(x) * ONE + int(y)
	A.append((a, p))

def cmp(x, y):
	ax, px = x
	ay, py = y
	tx, ty = ax * px * (ONE - py), ay * py * (ONE - px)
	return tx - ty

A.sort(key = cmp_to_key(cmp), reverse = True)
ans, s = 0, 0
for (a, p) in A:
	p = p / ONE
	ans += a * (p * 2 - 1.0) + s * (1.0 - p)
	s += a * p
print('%.6f' % ans)
