n=int(raw_input())
jc=1
ans=1
for i in range (2,n+1):
    jc=jc*i
    ans+=jc
print ans
