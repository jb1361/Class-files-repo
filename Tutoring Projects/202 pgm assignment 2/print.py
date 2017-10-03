def printstr(n):
	if n == 0:
		print()
	else:
		print('*', end = '')
		return printstr(n-1)

def tri(m,n):
	if m == n:
		printstr(m)
		printstr(n)
	else:
		printstr(m)
		tri(m+1,n)
		printstr(m)
		
		
tri(3,5)