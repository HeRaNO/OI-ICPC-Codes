n, m = map(int, input().split())
print("Victory" if n % (m + 1) > 0  else "Defeat")
