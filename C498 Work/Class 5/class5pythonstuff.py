import pandas as pd
import pandasql

aadhaar_data = pd.read_csv('aadhaar_data.csv')
aadhaar_data.rename(columns = lambda x: x.replace(' ', '_').lower(),inplace = True)

q = "SELECT * FROM aadhaar_data LIMIT 20"
sqlsolution = pandasql.sqldf(q.lower(), locals())
print(sqlsolution)
q2 = "SELECT district,sub_district, sum(aadhaar_generated) FROM aadhaar_data WHERE age > 50 GROUP BY district, sub_district"
sqlsolution2 = pandasql.sqldf(q2.lower(), locals())
print(sqlsolution2)


