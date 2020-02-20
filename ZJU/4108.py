T = int(input())
while T > 0:
	a, b = input().split()
	a = int(a)
	a -= 1
	a %= 3
	if a != 1:
		a = 0
	b = int(b)
	b %= 3
	if b != 1:
		b = 0
	print(a ^ b)
	T -= 1
