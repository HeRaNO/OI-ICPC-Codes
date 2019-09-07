import sys

a = []
m = []
f = []

def exgcd(a,b):
	if b==0:
		return a,1,0
	res,x,y = exgcd(b, a % b)
	t = x
	x = y
	y = t - (a // b) * y
	return res,x,y

def exCRT(n):
	M = m[1]
	ans = a[1]
	for i in range(2, n+1):
		g,x,y = exgcd(M, m[i])
		if (a[i] - ans) % g != 0:
			return -1
		x = (a[i] - ans) // g * x % (m[i] // g)
		ans = ans + x * M
		M = M // g * m[i]
		ans %= M
	ans = (ans + M) % M
	if ans == 1:
		return ans + M
	return ans

f.append(0)
f.append(1)
f.append(1)
m.append(0)
a.append(0)

for i in range(3,90):
	f.append(f[i-1]+f[i-2])

n = int(input())
for i in range(1,n+1):
	x,y=input().split(' ')
	m.append(int(x))
	a.append(int(y))

res=exCRT(n)

if res > 1000000000000000:
	print('Tankernb!')
	sys.exit(0)

if res==-1:
	print('Tankernb!')
	sys.exit(0)

for i in range(2,90):
	if res == f[i]:
		print('Lbnb!')
		sys.exit(0)

print('Zgxnb!')
