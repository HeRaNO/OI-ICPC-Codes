import sys

sys.setrecursionlimit(1000000)

T = int(input())
while T > 0:
	T -= 1
	s = input().strip()
	print(eval(s.replace('/', '//')))
