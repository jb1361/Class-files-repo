import pandas as pd
import numpy as np

titanic_df = pd.read_csv('titanic_data.csv')
perish_survive_df = titanic_df[['PassengerId','Survived']]
predictions_df = perish_survive_df[['PassengerId', 'Survived']]
passenger_info_df = titanic_df[['PassengerId','Sex','Age','Pclass']]
#passenger_info_df = passenger_info_df.fillna(passenger_info_df['Age'].mean())
#print(passenger_info_df)
#sets up a prediction dataframe with passengerid and weather they survived
#after our predictions we will compare the values of this dataframe to perish_survive_df and find our accuracy
predictions_df.loc[predictions_df.Survived == 1, 'Survived'] = 3
predictions_df.loc[predictions_df.Survived == 0, 'Survived'] = 3

#print(titanic_df)
#print(perish_survive_df)
#print(predictions_df)


compute_weight_df = predictions_df[['PassengerId']]
compute_weight_df['value'] = 0
#print(compute_weight_df)
##if the passenger is above a threshhold they survived
def predict():
	for i,val in enumerate(compute_weight_df['value']):
		if (val >= 4):		
			predictions_df.loc[predictions_df.PassengerId == i+1,'Survived'] = 1
		else:
			predictions_df.loc[predictions_df.PassengerId == i+1,'Survived'] = 0
	return (accuracy())
	
	##add in weights to determine how likely the passenger survived
def compute_weight(passenger):

	for i,sex in enumerate(passenger['Sex']):	
		if(sex == 'female'):
			compute_weight_df.loc[compute_weight_df.PassengerId == i+1,'value'] += 4
		else:
			compute_weight_df.loc[compute_weight_df.PassengerId == i+1,'value'] += 1
		
	for i,age in enumerate(passenger['Age']):	
		if(age < 13):
			compute_weight_df.loc[compute_weight_df.PassengerId == i+1,'value'] += 0
		else:
			compute_weight_df.loc[compute_weight_df.PassengerId == i+1,'value'] += 0
	
	for i,pclass in enumerate(passenger['Pclass']):
		
		if(pclass == 1):
			compute_weight_df.loc[compute_weight_df.PassengerId == i+1,'value'] += 0
		if(pclass == 2):
			compute_weight_df.loc[compute_weight_df.PassengerId == i+1,'value'] += 0
		if(pclass == 3):
			compute_weight_df.loc[compute_weight_df.PassengerId == i+1,'value'] += 0
			
	return(predict())

	
	
def accuracy():
	numerator = predictions_df.index.max()
	denominator = 0
	for i,val in enumerate(predictions_df['Survived']):
		value = perish_survive_df.loc[perish_survive_df['PassengerId'] == i]	
		if (val == value['Survived'].any()):
			denominator += 1
	return(print('Accuracy: ' + str(print_accuracy(numerator,denominator)) + '%'))
	
	
def print_accuracy(num, denom):
	print(compute_weight_df)
	print(perish_survive_df)
	print(predictions_df)
	print(perish_survive_df['Survived'].value_counts())
	print(predictions_df['Survived'].value_counts())
	print(compute_weight_df['value'].value_counts())
	print('Mean of weight: ' +  str(compute_weight_df.value.mean()))
	print('Numerator: ' + str(num) +' ' +  'Denominator:' + str(denom))
	acc = (denom/num) * 100
	return acc
	
	
	
compute_weight(passenger_info_df)	
	
	
#???	
