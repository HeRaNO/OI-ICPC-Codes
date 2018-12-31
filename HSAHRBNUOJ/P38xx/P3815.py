n=int(raw_input())
l,r=0,1
while r ** 2 <= n:
	l=r;r=r*2
while l+1<r:
	mid=(l+r)/2
	if mid ** 2 <= n:
		l=mid
	else:
		r=mid
if r ** 2 <= n:
	print r
else:
	print l