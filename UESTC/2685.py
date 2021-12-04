# Author: Macaron_lin
n, x, y = int(input()), list(map(int, input().split())), list(map(int, input().split()))
x.sort()
y.sort()
ans1, ans2, tmp = sum((x[i] - y[i]) * (x[i] - y[i]) for i in range(0, n)), sum((x[i] - y[n - 1 - i]) * (x[i] - y[n - 1 - i]) for i in range(0, n)), sum(x[i] - y[i] for i in range(0, n))
D = int(input())
ans3 = min(ans1 + 2 * tmp * d + d * d * n for d in range(-D, D + 1))
print(ans2, ans1)
print(ans3)
