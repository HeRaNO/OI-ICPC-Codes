s = input()
while True:
	try:
		s = input()
	except Exception as e:
		break
	try:
		eval(s)
	except Exception as e:
		print('No')
	else:
		print('Yes')
