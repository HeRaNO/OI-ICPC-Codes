def fac(x):
	ans = 1
	for i in range (2,x+1):
		ans = ans * i
	return ans

n = int(raw_input())
ans = 1
for i in range (2,n+1):
	ans = ans + fac(i)
print ans
