import pandas as pd

baseball_data = pd.read_csv('Master.csv')

baseball_data['height-plus-weight'] = baseball_data['height'] + baseball_data['weight']
baseball_data[['nameLast','nameGiven','height-plus-weight']].to_csv('heightplusweight.csv')

baseball_data['fullname'] = baseball_data['nameGiven']+ ' ' + baseball_data['nameLast']

baseball_data[['fullname', 'birthCountry']].to_csv('playerslocation.csv', index = False)

ven_count = baseball_data['birthCountry'].value_Counts()['Venszuela']
print('NUmber of players from Venszuela: ' + ven_count)