import csv
import pandas as pd
import tensorflow as ts
data = pd.DataFrame(pd.read_csv('titanic_data.csv'))

Pclass = data['Pclass']
sex = data['Sex']
age = data['Age']
fare = data['Fare']



