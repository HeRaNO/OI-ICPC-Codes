n = int(input())
d = list(map(int, input().split()))
l, r, h, a, x = map(int, input().split())
cnt = 0
for di in d:
	if l <= x + di and x + di <= r:
		cnt += 1
if cnt * a >= h:
	print("YES")
	print(cnt)
else:
	h -= cnt * a
	mx = 0
	for i in range(n):
		for j in range(i, n):
			if d[j] - d[i] <= r - l:
				mx = max(mx, j - i + 1)
	mx *= a
	ans = h // mx
	if h % mx != 0:
		ans += 1
	print("NO")
	print(ans)
