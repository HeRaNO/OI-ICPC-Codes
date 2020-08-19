s = input()
s = s.replace('(', '**(')

print(eval(s))
