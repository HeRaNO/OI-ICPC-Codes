n, m = map(int, input().split())
a, ans = [], []
for i in range(n):
	a.append(list(map(int, input().split())))
for b in map(list, zip(*a)):
	b.sort()
	ans.append(b[(n - 1) >> 1])
dif = sum(sum(abs(ans[j] - a[i][j]) for j in range(m)) for i in range(n))
print(dif)
print(' '.join(map(str, ans)))
