import pandas as pd

import scipy as sp
from scipy import stats
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab



hourly_entries_df = pd.DataFrame(pd.read_csv('turnstile_data_master_with_weather.csv'))

norain_df = hourly_entries_df.loc[hourly_entries_df['rain'] == 0]
rain_df = hourly_entries_df.loc[hourly_entries_df['rain'] == 1]

x = norain_df['ENTRIESn_hourly'].hist()
y = rain_df['ENTRIESn_hourly'].hist()
#plt.show()

x_mean = np.mean(norain_df['ENTRIESn_hourly'])
y_mean = np.mean(rain_df['ENTRIESn_hourly'])

U,p = stats.mannwhitneyu(norain_df['ENTRIESn_hourly'], rain_df['ENTRIESn_hourly'])

print('Mann-Whitney Test: ' + str(U))
print('p-Value: ' + str(p))

print('Null Hypothesis: ' + str(p*2))

"""
The null hypothesis is less than 5% threshhold so we can conclude that the entries are statistically different between rain and no rain.
"""


features = hourly_entries_df[['rain', 'precipi', 'Hour', 'meantempi']]
features = features.fillna(features.mean())
features = (features - features.mean())/features.std()

values = hourly_entries_df['ENTRIESn_hourly']
values =(values - values.mean())/values.std()
m = len(values)
features['ones'] = np.ones(m)

features_array = np.array(features)
values_array = np.array(values)


alpha = 0.1
num_iterations = 750
theta_descent = np.zeros(len(features.columns))

cost_history = []

for i in range(num_iterations):
    predicted_value = np.dot(features_array, theta_descent)
    theta_descent = theta_descent + alpha/m * np.dot(values_array - predicted_value, features_array)
    sum_of_square_errors = np.square(np.dot(features_array, theta_descent) - values_array).sum()
    cost = sum_of_square_errors / (2 * m)
    cost_history.append(cost)

cost_history = pd.Series(cost_history)
predictions = np.dot(features_array, theta_descent)

print('============================================')
print('Cost History: ', cost_history)
print('Predictions: ',predictions)
print('Alpha: ', alpha)
print('Iterations: ',num_iterations)

data_predictions = np.sum((values - predictions)**2)
mean = np.mean(values)
sq_mean = np.sum((values - mean)**2)

r = 1 - data_predictions / sq_mean
print('R: ', r)

