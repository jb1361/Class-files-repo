import numpy as np
import pandas as pd


Location = r'employee.csv'
ndf = pd.DataFrame(pd.read_csv(Location)) 

print(ndf)
print('============================')
ndf['Annual_Salary'].replace(regex=True,inplace=True,to_replace=r'\D',value=r'')
s = pd.Series(ndf['Annual_Salary'])
max = pd.to_numeric(s).max()
print(max)
#test = ndf.loc[ndf['Annual_Salary'] == max]
#print(test)