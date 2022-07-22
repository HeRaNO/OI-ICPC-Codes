from math import sqrt, pi
a, b, c = map(int, input().split())
r = (a * b + a * c + b * c - sqrt(a ** 2 * b ** 2 + a ** 2 * c ** 2 + b ** 2 * c ** 2)) / (2 * (a + b + c))
print('%.2f' % (4 / 3 * pi * r ** 3))
