n, ans = int(input()), 0
for i in range(n):
	l, r = map(int, input().split())
	ans += l ** 2 + r ** 2 + l * r
print('%.3f' % (ans / 3))
