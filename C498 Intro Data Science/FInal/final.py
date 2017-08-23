import pandas as pd
import numpy as np


#1 ===========================================
data_df = pd.read_csv('APData.csv')
#replace NR with zeros
data_df = data_df.replace('NR', 0)
#make make everything lowercase
data_df.rename(columns = lambda x: x.replace(' ', '_').lower(),inplace = True)
#replace 2 with two because the sql questions later on will provide errors if left as 2
data_df.rename(columns = lambda x: x.replace('2', 'two').lower(),inplace = True)
language = data_df['language'].str.lower()
data_df['language'] = language
print(data_df)
#===================================

#2 ============================================
#gets the dataframes we want to work with
twoa_df = data_df['twoa']
twob_df =  data_df['twob']
twoc_df = data_df['twoc']
twod_df = data_df['twod']

#the last dataframes were strings so we need to convert them to ints
twob_df = pd.to_numeric(twob_df)
twoc_df = pd.to_numeric(twoc_df)
twod_df = pd.to_numeric(twod_df)
#add values back to data_df
data_df['twob'] = twob_df
data_df['twoc'] = twoc_df
data_df['twod'] = twod_df


twoamean = np.mean(twoa_df)
twoamedian = np.median(twoa_df)
twoastd = np.std(twoa_df)

twobmean = np.mean(twob_df)
twobmedian = np.median(twob_df)
twobstd = np.std(twob_df)

twocmean = np.mean(twoc_df)
twocmedian = np.median(twoc_df)
twocstd = np.std(twoc_df)

twodmean = np.mean(twod_df)
twodmedian = np.median(twod_df)
twodstd = np.std(twod_df)



print('==========================================================')
print('2a Statistics')
print('2a Mean: ', twoamean)
print('2a Median: ', twoamedian)
print('2a STD: ', twoastd)

print('2b Statistics')
print('2b Mean: ', twobmean)
print('2b Median: ', twobmedian)
print('2b STD: ', twobstd)

print('2c Statistics')
print('2c Mean: ', twocmean)
print('2c Median: ', twocmedian)
print('2c STD: ', twocstd)

print('2d Statistics')
print('2d Mean: ', twodmean)
print('2d Median: ', twodmedian)
print('2d STD: ', twodstd)
print('==========================================================')

#===============================================

#3 ===========================================
import pandasql
#this line was used to make sure our sql queries were correct
#print(data_df['language'].value_counts())

#i #this satifies ii also but I will be doing it anyway (we could also put limit 3 at the end to only display the first couple)
q = "select language from data_df group by language order by count(*) desc "
most = pandasql.sqldf(q.lower(), locals())
print('The most common languages in descending order are: ')
print(most)
#jscrip, scratch, and java are the most common
#==========

#ii much like i but in reverse order
q = "select language from data_df group by language order by count(*)"
least = pandasql.sqldf(q.lower(), locals())
print('The least common languages in ascending order are: ')
print(least)
print()
# alice, c++, and processing are the least common
#========

#iii 
q = "select avg(twoa) as twoa,avg(twob) as twob,avg(twoc) as twoc,avg(twod) as twod from data_df"
average = pandasql.sqldf(q.lower(), locals())

mostdifficult = pandasql.sqldf(q.lower(), locals())
getmax =  mostdifficult.min(axis = 1)
getcolumn = average[average.isin(getmax)]
result = getcolumn.dropna(axis = 1)
result1 = list(result)
print('The most difficult question is: ',result1)

#=======

#iv =========
q = "select avg(twoa) as twoa,avg(twob) as twob,avg(twoc) as twoc,avg(twod) as twod from data_df"
average = pandasql.sqldf(q.lower(), locals())
mostdifficult = pandasql.sqldf(q.lower(), locals())
getmax =  mostdifficult.max(axis = 1)
getcolumn = average[average.isin(getmax)]
result = getcolumn.dropna(axis = 1)
result2 = list(result)
print('The lest difficult question is: ',result2)

#==========


#v ===========

q = "select id from data_df where twoc < 2 "
ids1 = pandasql.sqldf(q.lower(), locals())
print('IDs of students who scored less than 2 on 2c: ')
print(ids1)
print()

#============

#vi ============
q = "select avg(twod) as twod from data_df"
mean = pandasql.sqldf(q.lower(), locals())
q = "select id from data_df where twod < (select avg(twod) as twod from data_df)"
ids2 = pandasql.sqldf(q.lower(), locals())
print(ids2)
#============

#vii =============

import sqlite3
con = sqlite3.connect("database.db")
cur = con.cursor()

most.to_sql('i',con,if_exists='replace')
least.to_sql('ii',con,if_exists='replace')	
pd.DataFrame(result1).to_sql('iii',con,if_exists='replace')	
pd.DataFrame(result2).to_sql('iv',con,if_exists='replace')	
ids1.to_sql('v',con,if_exists='replace')	
ids2.to_sql('vi',con,if_exists='replace')
#============

#=============================================================

#4
import scipy as sp
from scipy import stats
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt

plt.hist(twoc_df)
plt.show()
plt.hist(twod_df)
plt.show()

#======================

#5 ===========================
t, p = stats.ttest_ind(twoc_df,twod_df)
print('T: ',t)
print('P: ',p)
print()
#==============================


#6 ====================================

features = data_df[['twob', 'twoc', 'twod']]
#features = pd.DataFrame(twob_df,twoc_df,twod_df)
features = (features - features.mean())/features.std()

values = data_df['decision']
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
#===========================
#7 ===================================
data_predictions = np.sum((values - predictions)**2)
mean = np.mean(values)
sq_mean = np.sum((values - mean)**2)

r = 1 - data_predictions / sq_mean
print('R: ', r)
print()
#========================

#8 ===================================
from sklearn import cluster
data_kmeans = data_df[['id','twob','twoc','twod']]
mat = data_kmeans.as_matrix()
k_means = cluster.KMeans(n_clusters = 5).fit(mat)
print(k_means.labels_)
#=============================================


#9 =====================================

language_decision_df = data_df[['language', 'decision']]
accepted = language_decision_df.loc[language_decision_df.decision == 1]
declined = language_decision_df.loc[language_decision_df.decision == 0]
print(language_decision_df)
print(accepted)
print(declined)
acount = accepted['language'].value_counts()
dcount = declined['language'].value_counts()
print(acount)
print(dcount)

#we dont really have enough data to make an a connection to a certain language and to getting accepted.
#in the data provided there were way more people writing in javascript than any other language thus more studends that used javascript got accepted.
#===============================================


