n = int(input())
k = n >> 1
ans = 1
for i in range(n-k+1,n+1):
	ans *= i
for i in range(1,k+1):
	ans //= i
print (ans)
