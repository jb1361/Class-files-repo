import pandas as pd
import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt


data = pd.DataFrame()
poverty = pd.DataFrame()
incomepercap = pd.DataFrame()
incomepercaperr = pd.DataFrame()
unemployment = pd.DataFrame()
pop = pd.DataFrame()

def load_data():
	global poverty
	global incomepercap
	global incomepercaperr
	global unemployment
	global pop
	data = pd.read_csv('acs2015_county_data.csv', encoding = "ISO-8859-1")
	
	incomepercap = data['IncomePerCap']
	incomepercaperr = data['IncomePerCapErr']
	unemployment = data['Unemployment']
	pop = data['Black']
	poverty = data['ChildPoverty']
	gradient_descent()
	#poverty = poverty/100

	
	
def gradient_descent():
	
	incomepercapupper = incomepercap + incomepercaperr
	incomepercaplower = incomepercap - incomepercaperr
	
	feature1 = (1-((incomepercapupper-incomepercaplower)/incomepercap))
	feature2 = (1-(unemployment/100))
	feature3 = (1-(pop/100))
	
	
	#features = [feature1, feature2,feature3]
	features = [feature1, feature2]
	features_array = np.array(features).transpose()

	
	values_feature = poverty/100
	
	for i,e in enumerate(values_feature):
		if(np.isnan(e)):	
			values_feature[i] = 0
						
	values_array = np.array(values_feature)
	
	"""
	#testing
	#features = [incomepercap, unemployment]
	#features_array = np.array(features).transpose()
		
	actual_values = np.array(poverty)
	for i,e in enumerate(actual_values):
		if(np.isnan(e)):	
			actual_values[i] = 0
	values_array = actual_values		
		"""	
			
			
			
	m = len(values_array)

	alpha = 0.000001
	num_iterations = 2000000
	
	theta_descent = [0.0,0.0]
	#theta_descent = [0.0,0.0,0.0]
	cost_history = []
	#actual gradient descent part
	for i in range(num_iterations):
		#hypothesis
		predicted_values = np.dot(features_array, theta_descent)
			
		#next theta
		theta_descent = theta_descent + alpha/m * np.dot(values_array - predicted_values, features_array)
		
		#get "corectness"
		sum_of_square_errors = np.square(np.dot(features_array, theta_descent) - values_array).sum()
		cost = sum_of_square_errors / (2 * m)
		cost_history.append(cost)
		#this causes lag
		if(i % 1000 == 0):
			print('Epoch: ' + str(i/1000) + ' : ' + 'Cost: ' + str(cost_history[i]))	
	
	print('============================================')
	#print('Cost History: ', cost_history)
	print('Theta Descent: ',theta_descent)
	print('Alpha: ', alpha)
	print('Iterations: ',num_iterations)
	
	
	
	featuress = [incomepercap,unemployment]
	#features = [incomepercap,unemployment,pop]
	features_arrayy = np.array(featuress).transpose()
	predictions = np.dot(features_arrayy, theta_descent)	
	predictions = predictions/100
	
	actual_values = np.array(poverty)
	
	for i,e in enumerate(actual_values):
		if(np.isnan(e)):	
			actual_values[i] = 0
			
	meandiff = abs(actual_values.mean() - predictions.mean())
	predictions = predictions - meandiff

	
	data_predictions = np.sum((actual_values - predictions)**2)
	mean = np.mean(actual_values)
	sq_mean = np.sum((actual_values - mean)**2)

	r = 1-(data_predictions / sq_mean)
	print('R: ', r)
	print()
	
	#print('Normalized Features: ',features_array)
	print('Actual Poverty Rate: ', actual_values)	
	print('Predicted Poverty Rate: ',predictions)
	
	
	
	print('============================================')
	fig, ax = plt.subplots()
	ax.plot(actual_values,'o',markersize = 1, color = 'green', label = 'Actual Poverty')
	ax.plot(predictions,'o',markersize = 1, color = 'blue', label = 'Predicted Poverty')
	plt.legend()
	fig2, ax2 = plt.subplots()
	ax2.plot(cost_history,'o',markersize = 1, color = 'blue')
	plt.show()
	#===================================================================================================
	
	
load_data()