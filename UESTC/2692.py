import string
m, n = map(int, input().split())
print((n % m) * 'a' + (n // m) * string.ascii_lowercase[:m])
