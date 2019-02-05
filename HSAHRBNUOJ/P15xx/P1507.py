s = raw_input()
fac = []
c = []
fac.append(1)
n = len(s)
ans = 0
for i in range(1,n+1):
	fac.append(fac[i-1]*i)
for i in range(0,26):
	c.append(0)
for i in range(0,n):
	c[ord(s[i])-97] += 1
for i in range(0,n-1):
	pt = 0
	x = ord(s[i]) - 97
	for j in range (0,x):
		if c[j] > 0:
			c[j] -= 1
			p = fac[n-i-1]
			for k in range(0,26):
				p //= fac[c[k]]
			c[j] += 1
			pt += p
	c[x] -= 1
	ans += pt
print ans+1
