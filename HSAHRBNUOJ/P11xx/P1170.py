s=raw_input()
e=""
p=""
x=len(s)
for i in range (0,x):
	if s[i]=='^':
		e=e+'*'
		e=e+'*'
	else:
		e=e+s[i]
y=len(e)
a=[]
b=[]
for i in range (0,y):
	if e[i]=='(':
		a.append(i)
	if e[i]==')':
		if len(a)==0:
			b.append(i)
		else:
			a.pop()

for i in range (0,y):
	if not (i in a) and not (i in b):
		p=p+e[i]

print eval(p)
