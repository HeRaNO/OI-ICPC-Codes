n, k = map(int, input().split())
f = [[0 for i in range(k)] for i in range(k)]
for i in range(n):
	x, y = map(int, input().split())
	f[x % k][y % k] ^= 1

def check():
	for i in range(k):
		for j in range(k):
			if f[i][j] ^ f[i][0] != f[0][j] ^ f[0][0]:
				return False
	return True

print("YES") if check() else print("NO")
