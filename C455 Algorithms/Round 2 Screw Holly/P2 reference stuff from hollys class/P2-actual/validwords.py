from sys import stdin

#===========================
#This is really bad, I want to implement a hash map but it I havnt spent too long making it work properly.
# I think it just makes a size m list with size m elements inside.
#===========================

words = []
m = 466511
dict = [[None]] * m 
dict2 = [[]] * 26
def load_dict():
	print("Loading Dictionary")
	file = "./dictionary.txt"
	f = open(file)
	line = f.readline()
	while(line):
		dict2.append(line)
		id = hash(line) % m	
		dict[id].append(line)
		line = f.readline()
	return

def read_input():
	for line in stdin:
		words.append(line)
	load_dict()
	compare()
	return 0
	
actual_words = []

def compare():
	print("Comparing Words To Dictionary")
	print(len(words))

	for word in words:	
		id = hash(word) % m
		if (dict[id] != None):
			for item in dict[id]:				
				if(item == word):
					print("Found: " + word)
					actual_words.append(word)
							
	for word in actual_words:
		print(word)	
	print("Found " + str(len(actual_words)) + " words.")
	return	
	
	
	
read_input()





