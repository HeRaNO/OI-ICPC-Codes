n = int(input())
print(sum(n // i for i in range(1, n + 1)) - n)
