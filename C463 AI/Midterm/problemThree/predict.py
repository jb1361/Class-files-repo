import csv
import pandas as pd
import numpy as np
from sklearn import linear_model
import math
data = pd.DataFrame(pd.read_csv('titanic_data.csv'))

Pclass = data['Pclass']
sex = data['Sex']
age = data['Age']
fare = data['Fare']
survived = data['Survived']


Pclass_train = Pclass[0:math.floor(len(Pclass)/2)]
Pclass_test = Pclass[(math.floor(len(Pclass)/2)+1):len(Pclass)]

sex_train = sex[0:math.floor(len(Pclass)/2)]
sex_test = sex[(math.floor(len(Pclass)/2)+1):len(Pclass)]

for i,s in enumerate(sex_train):
	if s == 'male':
		sex_train[i] = 1
	else:
		sex_train[i] = 0
print(sex_train)


age_train = age[0:math.floor(len(Pclass)/2)]
age_test = age[(math.floor(len(Pclass)/2)+1):len(Pclass)]

fare_train = fare[0:math.floor(len(Pclass)/2)]
fare_test = fare[(math.floor(len(Pclass)/2)+1):len(Pclass)]

survived_train = survived[0:math.floor(len(Pclass)/2)]
survived_test = survived[(math.floor(len(Pclass)/2)+1):len(Pclass)]

training_data = [Pclass_train,sex_train,age_train,fare_train]

regr = linear_model.LinearRegression()
regr.fit(training_data, survived_train)
