import subprocess

cmd = ""
while True:
	try:
		x = input().strip()
	except Exception as e:
		break
	cmd = cmd + x + '\n'

b = subprocess.run(['python3', '-c', cmd], stdout=subprocess.PIPE).stdout
out = b.decode().strip()
print(out)
