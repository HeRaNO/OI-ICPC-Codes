n = 1

while True:
	def find_message(s):
		for i in range(1, len(s) + 1):
			if s[-i] == ':':
				return len(s) - i
		return None

	try:
		line = input()
		print(n)
		n += 1

		# Find and delete message
		message_start_pos = find_message(line)
		message, line = line[message_start_pos + 1:], line[: message_start_pos]
		line.strip()

		def reach_to_ch(l, ch):
			r = l
			while r < len(line):
				if line[r] == ch:
					break
				r += 1
			return r

		l = 0

		while l < len(line):
			if line[l] == ' ':
				l += 1
				continue
			if line[l].isdigit():
				# possible: asctime, level_no, file_name
				if l + 4 < len(line) and line[l + 4] == '-':
					# must be asctime
					print(f'<%(asctime)s,{line[l: l + 23]}>')
					l += 23
				elif line[l: l + 2] in {'10', '20', '30', '40', '50'}:
					# must be level_no
					print(f'<%(levelno)s,{line[l: l + 2]}>')
					l += 2
				else:
					# must be file_name
					r = reach_to_ch(l, '.')
					r = reach_to_ch(r, ' ')
					print(f'<%(filename)s,{line[l: r]}>')
					l = r
			elif line[l].isupper():
				# possible: path_name, file_name, level name
				if line[l + 1] == ':':
					# must be path_name
					r = reach_to_ch(l, '.')
					r = reach_to_ch(r, ' ')
					print(f'<%(pathname)s,{line[l: r]}>')
					l = r
				elif line[l: l + 5] == 'DEBUG' or \
					 line[l: l + 4] == 'INFO' or \
					 line[l: l + 7] == 'WARNING' or \
					 line[l: l + 5] == 'ERROR' or \
					 line[l: l + 8] == 'CRITICAL':
					r = reach_to_ch(l, ' ')
					print(f'<%(levelname)s,{line[l: r]}>')
					l = r
				else:
					# must be file name
					r = reach_to_ch(l, '.')
					r = reach_to_ch(r, ' ')
					print(f'<%(filename)s,{line[l: r]}>')
					l = r
			elif line[l].islower():
				# must be logger name, line no, thread id, thread name, process id, file name
				if ':' in line[l: l + 8]:
					# must be logger name, line no, thread id, thread name, process id
					r = reach_to_ch(l, ' ')
					t = line[l: r].split(':')
					if t[0] == 'logger':
						print(f'<%(name)s,{line[l: r]}>')
					elif t[0] == 'line':
						print(f'<%(lineno)d,{line[l: r]}>')
					elif t[0] == 'thread':
						if t[1].isdigit():
							print(f'<%(thread)d,{line[l: r]}>')
						else:
							print(f'<%(threadName)s,{line[l: r]}>')
					elif t[0] == 'process':
						print(f'<%(process)s,{line[l: r]}>')
					else:
						raise RuntimeError
					l = r
				else:
					# must be file name
					r = reach_to_ch(l, '.')
					r = reach_to_ch(r, ' ')
					print(f'<%(filename)s,{line[l: r]}>')
					l = r
			else:
				raise RuntimeError
		print(f'<%(message)s,{message}>')
	except EOFError:
		break
