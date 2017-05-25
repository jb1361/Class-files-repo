import pandas as pd
import pandasql

#get data from csv and put into a dataframe then replace all spaces with '_'
aadhaar_data = pd.DataFrame(pd.read_csv('aadhaar_data.csv'))
aadhaar_data.rename(columns = lambda x: x.replace(' ', '_').lower(),inplace = True)

#1
totalaccepted = pd.DataFrame(aadhaar_data['enrolment_rejected'])
totalaccepted = totalaccepted.loc[totalaccepted['enrolment_rejected'] == 0]
print('Total Accepted: ' + str(totalaccepted.index.max()))
#2

totalrejected = pd.DataFrame(aadhaar_data['enrolment_rejected'])
totalrejected = totalrejected['enrolment_rejected'].sum()
print('Total Rejected: ' + str(totalrejected))
#3
totalsmf = pd.DataFrame(aadhaar_data['gender'].value_counts())
print(totalsmf)

#4
totalbyagegroup_df = pd.DataFrame(aadhaar_data['age']) 
lessthan25 = totalbyagegroup_df.loc[totalbyagegroup_df['age'] < 25]
over55 = totalbyagegroup_df.loc[totalbyagegroup_df['age'] > 55]
between = totalbyagegroup_df.loc[totalbyagegroup_df['age'] < 55]
between = between.loc[totalbyagegroup_df['age'] > 25]
print('Less than 25: ' + str(lessthan25.index.max()))
print('Over 55: ' + str(over55.index.max()))
print('Between 25 and 55: ' + str(between.index.max()))
#========================================================

weather_data = pd.DataFrame(pd.read_csv('weather_underground.csv'))

#5
q = "select count(*) from weather_data where rain = 1"
sumofrain = pandasql.sqldf(q.lower(), locals())
print('Ammount of days it rained: ' + str(sumofrain))


#6
q2 = "select count(*) from weather_data where fog = 1"
q3 = "select count(*) from weather_data where fog = 0"
sqlq = pandasql.sqldf(q2.lower(), locals())
sqlq2 = pandasql.sqldf(q3.lower(), locals())
fog = pd.DataFrame([[sqlq, sqlq2]], columns = ['Fog', 'No Fog'])
#print(sqlq.in)
print(fog)

#7
meantempi_df = pd.DataFrame(weather_data['meantempi'])
mean = meantempi_df['meantempi'].mean()
print('Mean: ' + str(mean))

print('================================')
#8
import json
import requests
import sqlite3

con = sqlite3.connect("music.db")
cur = con.cursor()
cur.execute("create table TopIndianListners(Artist text, Listeners text)")


#8.1
url2 = 'http://ws.audioscrobbler.com/2.0/?method=geo.gettopartists&country=India&api_key=4005c05d541d9a056136d5450be12883&format=json'
data2 = requests.get(url2).text
data2 = json.loads(data2)
artists = json.dumps(data2['topartists']['artist'],indent = 4)
print(artists)
listeners = json.dumps(data2['topartists']['artist']['listeners'])
#cur.execute(("insert into TopIndianListners ( Artist , Listeners "), artists,str(artists['listeners']))

