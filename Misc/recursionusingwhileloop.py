def whilerecur(x):
	while x < 5:
		x = whilerecur(x+1)
	return x
	
print(whilerecur(1))
