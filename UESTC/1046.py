def getRadix(n):
	if n[0] == '0':
		if n[1] == 'x' or n[1] == 'X':
			return 16
		return 8
	return 10

a = input()
a = int(a, getRadix(a))

b = input()
b = int(b, getRadix(b))

print(a + b)
