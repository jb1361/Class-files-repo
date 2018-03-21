word = input()
newword = ''
c = 1
for i in word:
	newword = newword + i
	x = c
	while x > 0:
		newword = newword + ' '
		x = x-1
	c = c + 1
print(newword)