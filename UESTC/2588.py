n = int(input())
res, las = 2, 0
for i in range(n):
    res, las = res + las, res
print(2 ** n - res)
