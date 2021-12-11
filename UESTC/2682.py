# Author: Macaron_lin
n = int(input())
a = list(map(int, input().split()))
mx = a.copy()
curmin = 10000000000
for i in range(n - 1, -1, -1):
    curmin = min(a[i], curmin)
    mx[i] = curmin

m = int(input())
q = list(map(int, input().split()))

for x in q:
    x -= 1
    print(a[x] - mx[x])