#need baseball_stats.baseball_stats_df
#features = height and weight

#def compute.cost(features,values,theta)(this is a dataframe)
#define an afrray of random values 0.0 to 1.0
#normal distribution
#m = len(values) # of data points

#sum of squar errors = numpy.square(numpy.dot(features, theta) - values)
#										Ypred				Yobserved
											
#cost = sum of square errors /(2*m)
#return cost

# def gradual descent(features,values,theta,alpha,num_interations)
# m = len(values)
# cost_history[]
# for i in range(num_interations)
# 		predictedvalues = numpy.dot(features,theta)
#		theta = theta - alpha/m * numpy.dot(predicted values - values), features)
#		computecost(features,values,theta)
#ret theta,pandas.series(cost,history)
#
import pandas as pd
import numpy as np
baseball_stats_df = pd.read_csv('baseball_stats.csv')

features = baseball_stats_df[['weight', 'height']]
features = features.apply(lambda x: x.str.strip() if isinstance(x, object) else x).replace('', np.nan)
features[['height', 'weight']]=   features[['height', 'weight']].convert_objects(convert_numeric=True)
features = features.fillna(features.mean())
features = (features - features.mean())/features.std()
print(features)
values = baseball_stats_df['HR'] 
values =(values - values.mean())/values.std()
print(values)
theta = np.random.normal(0.0,1.0,size = 2)
print(theta)
alpha = 0.05
num_interations = 1000

def compute_cost(features,values,theta):	
	m = len(values)
	print('length of m: ' + str(m))
	print('==========================')
	sum_of_square_errors = np.square(features.apply(lambda x: np.dot(x, theta),axis = 1) - values).sum()
	print('Sum of square errors: ' + str(sum_of_square_errors))
	print('==========================')
	cost = sum_of_square_errors /(2*m)
	
	print('Cost: ' + str(cost))
	return cost



def gradual_descent(features,values,theta,alpha,num_interations):
	m = len(values)
	cost_history = []
	for i in range(num_interations):
		predicted_values = np.dot(features,theta)
		theta = theta - (alpha/m * np.dot(predicted_values - values, features))
		final_cost = compute_cost(features,values,theta)
		print('iteration: ' + str(i))
	return theta,pd.Series(final_cost,cost_history)


print(gradual_descent(features,values,theta,alpha,num_interations))



