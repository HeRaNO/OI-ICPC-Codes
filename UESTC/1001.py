T = int(input())
while T > 0:
	s = int(input())
	a = s % 3
	b = s % 11
	if (a == 0) and (b == 0):
		print('yes yes')
	elif (a == 0) and (b != 0):
		print('yes no')
	elif (a != 0) and (b == 0):
		print('no yes')
	else:
		print('no no')
	T = T - 1
