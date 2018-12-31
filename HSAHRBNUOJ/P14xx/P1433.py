a=raw_input()
b=a[0:len(a)-1]
try:
	print eval(b)
except Exception:
	print "NO"
