import math
n, m = map(int, input().split())
x, y = map(int, input().split())
n, m = n // math.gcd(n, x), m // math.gcd(m, y)
print(n * m // 2) if n % 2 == 0 and m % 2 == 0 else print(n * m)
