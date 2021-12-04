import collections
n = int(input())
a = list(map(int, input().split()))[::-1]
q = collections.deque()
s = 0
for i in range(n):
	q.append(a[i]) if a[i] * i > s else q.appendleft(a[i])
	s += a[i]
mn = sum(q[n - 1 - i] * (i + 1) for i in range(n))
mx = sum(q[i] * (i + 1) for i in range(n))
print(mn, mx)
