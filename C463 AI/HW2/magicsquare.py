
from random import randint

n = int(input())
matrix  = []
x = 0 
while x < n:
	row = input()
	matrix.append(row.split())
	x = x +1

sum_of_rows = input()
sum_of_rows = sum_of_rows.split()

sum_of_columns = input()
sum_of_columns = sum_of_columns.split()
diag_sum = input()
diag_sum = diag_sum.split()


#print('row sums: ' + str(sum_of_rows))
#print('column sums: ' + str(sum_of_columns))
#print('diag sums: ' + str(diag_sum))
#print('matrix: ' + str(matrix))


def sum_row(row_num,matrix):
	sum = 0
	for i in range(0,n):
		if int(matrix[row_num][i]) != -1:
			sum = sum + int(matrix[row_num][i])
	return sum
	
def sum_col(col_num,matrix):
	sum = 0
	for i in range(0,n):
		if int(matrix[i][col_num]) != -1:
			sum = sum + int(matrix[i][col_num])
	return sum
	
def tlbr_diag_sum(matrix):
	sum = 0
	for i in range(0,n):
		if int(matrix[i][i]) != -1:
			sum = sum + int(matrix[i][i])
	return sum

def trbl_diag_sum(matrix):
	sum = 0
	for i in range(0,n):
		if int(matrix[i][(n-1)-i]) != -1:
			sum = sum + int(matrix[i][(n-1)-i])
	return sum
			
def checkmatrix(matrix):
	for row in range(0,n):
		for col in range(0,n):
			if matrix[row][col]==-1:
				return False
	for row in range(0,n):
		if sum_row(row,matrix)!= int(sum_of_rows[row]):
			return False
	for col in range(0,n):
		if sum_col(col,matrix)!= int(sum_of_columns[col]):
			return False
	if tlbr_diag_sum(matrix)!=int(diag_sum[0]):
		return False
	if trbl_diag_sum(matrix)!=int(diag_sum[1]):
		return False 
	return True 

def solvematrix(matrix):
	for i in range(0,n**2):
		row=i//n
		col=i%n
		if int(matrix[row][col])==-1:
			for value in range (1,10):
				matrix[row][col]=value 
				#print(matrix)
				if checkmatrix(matrix):
					return True
				else:
					if solvematrix(matrix):
						return True
			break
	matrix[row][col]=-1  

def format_output(row,matrix):
	out = ''
	for i in range(0,n):
		num =  matrix[row][i]
		out = out + str(num) + ' '
	return out
	
solvem = solvematrix(matrix)

if solvem:
	print('True')
	for i in range (0,n):
		print(format_output(i,matrix))
else:
	print('False')