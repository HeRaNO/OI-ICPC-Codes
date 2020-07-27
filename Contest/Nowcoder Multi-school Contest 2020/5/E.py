import math

not_prime = []
for i in range(1, 100005):
	not_prime.append(False)
prime = []

def LinearShaker(n):
	tot = 0
	for i in range(2, n + 1):
		if not not_prime[i]:
			prime.append(i)
			tot += 1
		for j in range(0, tot):
			if i * prime[j] > n:
				break
			not_prime[i * prime[j]] = True
			if i % prime[j] == 0:
				break

# LinearShaker(100001)
n = int(input())
s = input().split(' ')
a = []
v = []
ans = 1
for i in s:
	a.append(int(i) - 1)
	v.append(False)

for i in range(0, n):
	if v[i]:
		continue
	p = a[i]
	l = 1
	v[i] = True
	while p != i:
		v[p] = True
		l += 1
		p = a[p]
	ans = ans * l // math.gcd(ans, l)

print(ans)
