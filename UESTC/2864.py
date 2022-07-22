def main():
	T = int(input())
	while T > 0:
		n, m = map(int, input().split())
		print(Solve(n - 1, m - 1))
		T -= 1

def Solve(n, m):
	n, m = bin(n)[2:], bin(m)[2:]
	r = 0
	while n != "" or m != "":
		if n + m < m + n or m == "":
			r = r << 1 | int(n[0])
			n = n[1:]
		else:
			r = r << 1 | int(m[0])
			m = m[1:]
	return r

if __name__ == '__main__':
	main()