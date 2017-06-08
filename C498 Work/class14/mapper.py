import sys


for line in sys.stdin:
	line = line.strip() #remove whitespace
	words = line.split()
	for word in words:
		print('%s\t%s'%(word,1))

		
