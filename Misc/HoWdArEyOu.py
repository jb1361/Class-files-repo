word = input()
def howdareyou(s):
	ret = ""
	i = True  # capitalize
	for char in s:
		if i:
			ret += char.upper()
		else:
			ret += char.lower()
		if char != ' ':
			i = not i
	return ret
print(howdareyou(word))