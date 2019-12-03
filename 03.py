f = open('./03.txt', 'r')
lines = f.read().strip().split("\n")

paths = [{}, {}]

def get_path(i):
	wires = list(lines[i].split(","))
	x = 0
	y = 0
	res = {}
	step = 0
	for wire in wires:
		for i in range(int(wire[1:])):
			if wire[0] == 'U':
				y-=1
			if wire[0] == 'D':
				y+=1
			if wire[0] == 'L':
				x-=1
			if wire[0] == 'R':
				x+=1
			step += 1
			if (x, y) not in res:
				res[(x, y)] = step
	return res

paths = [get_path(0), get_path(1)]

intersections = set(paths[0].keys()) & set(paths[1].keys())
part1 = min([abs(x) + abs(y) for (x, y) in intersections])
part2 = min([paths[0][key] + paths[1][key] for key in intersections])

print(part1, part2)

def print_path():
	max_x = 0
	max_y = 0
	min_x = float("inf")
	min_y = float("inf")
	both = {**paths[0], **paths[1]}
	for (x, y) in both:
		max_x = max(max_x, x)
		max_y = max(max_y ,y)
		min_x = min(min_x, x)
		min_y = min(min_y, y)
	for y in range(min_y, max_y + 1):
		for x in range(min_x, max_x + 1):
			if x == 0 and y == 0:
				print('\x1b[6;31;43m' + 'o' + '\x1b[0m', end="")
			elif (x, y) in paths[0]:
				print('\x1b[6;30;42m' + 'x' + '\x1b[0m', end="")
			elif (x, y) in paths[1]:
				print('\x1b[6;33;41m' + 'x' + '\x1b[0m', end="")
			else:
				print('.', end="")
		print('')

# print_path()
