import csv
import pandas as pd
import math
data = pd.read_csv('student-mat.csv',delimiter =';')

percent = math.floor(len(data) * .70)

trainingSet = data[0:int(percent)]
testingSet = data[int(percent+1):len(data)]
testingSet = testingSet.reset_index(drop = False)


print(trainingSet)
