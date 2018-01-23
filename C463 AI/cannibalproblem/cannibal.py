#       c m
left = (3,3)
right = (0,0)
boat = (0,0)
path = []
history = []
def findpath():
	global left
	global right
	for c in range(3):
		for m in range(3):
			x = c 
			y = m
			while y > 0:
				left = (left[0],left[1]-1)
				y = y-1
			while x > 0:
				left = (left[0]-1,left[1])	
				x = x-1
			right = (3-left[0],3-left[1])
			history.append([left,right])
				
			print(history)
			if left[0] > left[1] or right[0] > right[1]:
				del history[:]
				left = (3,3)
				right = (0,0)
			if right[0] == 3 and right[1] == 3:
				path.append(history)
				del history[:]
				left = (3,3)
				right = (0,0)
			if right[0] > 3 or right[1] > 3:
				del history[:]
				left = (3,3)
				right = (0,0)
			if left[0] < 0 or left[1] < 0:
				del history[:]
				left = (3,3)
				right = (0,0)
				
#left = (1,left[1])
findpath()
print(path)