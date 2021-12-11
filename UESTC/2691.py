import collections
n = int(input())
a = list(map(int, input().split()))[::-1]
q = collections.deque()
s = 0
for i in range(n):
	q.append(a[i]) if a[i] * i > s else q.appendleft(a[i])
	s += a[i]
mn = sum(q[-i] * i for i in range(1, n + 1))
mx = sum(q[i] * (i + 1) for i in range(n))
print(mn, mx)
