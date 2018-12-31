s=raw_input()
e=""
x=len(s)
for i in range (0,x):
	if s[i]=='^':
		e=e+'*'
		e=e+'*'
	else:
		e=e+s[i]
print eval(e)
