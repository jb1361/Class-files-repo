import csv
import pandas as pd
import numpy as np
from sklearn import linear_model
import math
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt

data = pd.DataFrame(pd.read_csv('titanic_data.csv'))
data = data.fillna(0)

Pclass = data['Pclass']
sex = data['Sex']
age = data['Age']
fare = data['Fare']
survived = data['Survived']



#setting up training and testing data
Pclass_train = Pclass[0:math.floor(len(Pclass)/2)]
Pclass_test = Pclass[(math.floor(len(Pclass)/2)+1):len(Pclass)]
Pclass_test = Pclass_test.reset_index(drop = True)

sex_train = sex[0:math.floor(len(Pclass)/2)]
sex_test = sex[(math.floor(len(Pclass)/2)+1):len(Pclass)]
sex_test = sex_test.reset_index(drop = True)

for i,s in enumerate(sex_train):
	if s == 'male':
		sex_train[i] = 1
	else:
		sex_train[i] = 0
	
for i,s in enumerate(sex_test):
	if s == 'male':
		sex_test[i] = 1
	else:
		sex_test[i] = 0
	
age_train = age[0:math.floor(len(Pclass)/2)]
age_test = age[(math.floor(len(Pclass)/2)+1):len(Pclass)]
age_test = age_test.reset_index(drop = True)

fare_train = fare[0:math.floor(len(Pclass)/2)]
fare_test = fare[(math.floor(len(Pclass)/2)+1):len(Pclass)]
fare_test = fare_test.reset_index(drop = True)

survived_train = survived[0:math.floor(len(Pclass)/2)]
survived_test = survived[(math.floor(len(Pclass)/2)+1):len(Pclass)]
survived_test = survived_test.reset_index(drop = True)


training_data = np.array([Pclass_train,sex_train,age_train,fare_train])
testing_data = np.array([Pclass_test,sex_test,age_test,fare_test])


training_data = training_data.transpose()
testing_data = testing_data.transpose()


regr = linear_model.LinearRegression()
regr.fit(training_data, survived_train)




prediction = regr.predict(testing_data)

print('Linear Regression:')
# The coefficients
print('Coefficients: \n', regr.coef_)
# The mean squared error
print("Mean squared error: %.2f" % mean_squared_error(survived_test, prediction))
# Explained variance score: 1 is perfect prediction
print('Variance score: %.2f' % r2_score(survived_test, prediction))



for i,e in enumerate(prediction):
	if e >= .5:
		prediction[i] = 1
	else:
		prediction[i] = 0
	
total = len(prediction)
wrong = 0

for i,e in enumerate(prediction):
	if e != survived_test[i]:
		wrong = wrong + 1
		
print(str( 100* (1-(wrong/total))) + ' Accuracy')
print('========================================')
print('Gradient Descent:')


training_data = training_data.transpose()
testing_data = testing_data.transpose()


features_array = training_data
#===================================================================================================

#get values
values_array = survived_test
#===================================================================================================

m = len(values_array)
alpha = 0.00001
num_iterations = 100000

#2 is the number of features
theta_descent = [0.5,0.5,0.5,0.5]
cost_history = []
#actual gradient descent part
for i in range(num_iterations):
	#hypothesis
	predicted_values = np.dot(features_array.transpose(), theta_descent)

	#next theta
	theta_descent = theta_descent - alpha/m * np.dot((predicted_values-values_array), features_array.transpose())
	
	#get "corectness"
	sum_of_square_errors = np.square(np.dot(features_array.transpose(), theta_descent) - values_array).sum()
	cost = sum_of_square_errors / (2 * m)
	cost_history.append(cost)
	#this causes lag
	if(i % 1000 == 0):
		print('Epoch: ' + str(i/1000) + ' : ' + 'Cost: ' + str(cost_history[i]))
	
	
#all output and debugging 
cost_history = pd.Series(cost_history)


print('============================================')
#print('Cost History: ', cost_history)
print('Theta Descent: ',theta_descent)
print('Alpha: ', alpha)
print('Iterations: ',num_iterations)


predictions = np.dot(testing_data.transpose(), theta_descent)

sum_of_square_errors = ((predictions - survived_test)**2).sum()
sq_mean = (np.array(survived_test).mean())**2
r = 1 - (sq_mean/sum_of_square_errors)
print('R: ', r)

for i,e in enumerate(predictions):
	if e >= .5:
		predictions[i] = 1
	else:
		predictions[i] = 0
	
total = len(predictions)
wrong = 0

for i,e in enumerate(predictions):
	if e != survived_test[i]:
		wrong = wrong + 1
		
print(str( 100* (1-(wrong/total))) + ' Accuracy')
print('========================================')







