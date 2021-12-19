n = int(input())
for i in range(n):
	x = int(input())
	if x < 425:
		print('See you next year!')
	else:
		print('Passed!') if x < 550 else print('Excellent!')
