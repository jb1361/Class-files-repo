import numpy

numbers = [1,2,3,4,5,6]

print( numpy.mean(numbers))
print (numpy.median(numbers))
print (numpy.std(numbers))
num = numpy.array([1,2,3,4,5,6])
num = num/3.0
print(num)
num[2:5] = 15/75
print(num[0:5])


import numpy as np

twoD = np.array([[1,2,3],[4,5,6]], float)
print(twoD)
print(" ")
#2DArraySlicing
print(twoD [1][1])
print(" ")
print(twoD [1, :])
print(" ")
print(twoD [:,2])
print(" ")
array1 = np.array([1,2,3], float)
array2 = np.array([5,6,7], float)
print(array1 + array2)
print(" ")
print(array1 - array2)
print(" ")
print(array1 * array2)
print(" ")
array2d1  = np.array([[1,2],[3,4]],float)
array2d2 = np.array([[5,6],[7,8]],float)
print(array2d1 + array2d2)
print(" ")
print(array2d1 - array2d2)
print(" ")
print(array2d1 * array2d2)

import pandas as pd

series1 = pd.Series(['Alan' , 'Grant', 'TN', 45, -17])

print(series1)

series2 = pd.Series(['Dave', 'Lewis', 'KY', 39, -9], index = ['FirstName','LastName', 'State', 'age', 'demerits'])

print(" ")
print(series2)

#print(series2 ['state'])

cuteness = pd.Series([1,2,3,4,5], index = ['bug','fish','pig','puppy','kitten'])

print(cuteness > 3)

data = { 'year' :[2010,2011,2012,2011,2012], 'team' : ['Bears', 'Bears', ' Bears', 'Packers', 'Packers'], 'wins' :[11,8,10,15,11],
'loses' : [5,8,6,1,5]}

football = pd.DataFrame(data)

print(football)
print(" ")
d = { 'one' : pd.Series([1,2,3], index = ['a','b','c']),
	  'two' : pd.Series([1,2,3,4], index = ['a','b','c','d'])
	  }
df = pd.DataFrame(d)
print(df)

print(" ")

print(df.apply(np.mean))

print(" ")

print(df['one'].map(lambda x:x>=1))
print(" ")
print(df.applymap(lambda x:x>=1))
print(" ")

a1 = [1,2,3,4,5]
a2 = [2,3,4,5,6]
dotp = np.dot(a1,a2)
print(dotp)

print(" ")

b1 = [1,2]
b2 = [[2,4,6],[3,5,7]]

print(np.dot(b1,b2))
print(" ")

#visualize data (plot)
import matplotlib.pyplot as plt


names = ['Bob', 'Jessica','Mary','John','Mel']
births = [968,155,77,578,973]
BabyDataSet = list(zip(names,births))
print(BabyDataSet)
print(" ")
df = pd.DataFrame(data = BabyDataSet, columns = ['Names','Births'])
print(df)


#export datafram to csv file (comma seperated)
df.to_csv('births1880.csv',index = False, header = True)

print("===========================================")
#read a csv file
Location = r'births1880.csv'
ndf = pd.DataFrame(pd.read_csv(Location)) #<---- this line
print(ndf)
print(ndf.dtypes)
print(ndf.describe())
print("===========================================")


Sorted = df.sort_values(['Births'],ascending = False)

print(Sorted.head(1))


MaxName = df['Names'][df['Births'] == df['Births'].max()].values
print(MaxName)
print("===========================================")



df['Births'].plot()
plt.show()

print("===========================================")


