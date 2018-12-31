import math
r=int(raw_input())
ans=0
for i in range (-r,r+1):
    ans+=2*int(math.sqrt(r*r-i*i))+1
print ans
