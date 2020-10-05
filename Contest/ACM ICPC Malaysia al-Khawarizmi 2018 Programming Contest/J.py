f = [0, 1, 1]
for i in range(3, 501):
	f.append(f[i - 1] + f[i - 2])
while True:
	n = int(input())
	if n == -1:
		break
	print('Hour: %d: %d cow(s) affected'%(n, f[n]))
