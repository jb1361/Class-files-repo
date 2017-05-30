import pandas as pd
import numpy as np

df = pd.DataFrame(pd.read_csv('master.csv'))
print(pd.isnull(df['height']))
height_df = pd.DataFrame(df['height'])
height_df = height_df.fillna(height_df.mean())
print(height_df)

weight_df = pd.DataFrame(df['weight'])
weight_df2 = pd.DataFrame(df['weight'])
print(weight_df)
weight_df = weight_df.interpolate()
print(weight_df)
print(weight_df2)
weight_df2 = weight_df2.interpolate(method = 'polynomial', order = 2)
print(weight_df2)

baseball_df = pd.DataFrame(pd.read_csv('baseball_stats.csv'))
handedness_df = pd.DataFrame(baseball_df['handedness'])
print(handedness_df)

l_hand = baseball_df.loc[baseball_df['handedness'] == 'L']
print(l_hand)
r_hand =  baseball_df.loc[baseball_df['handedness'] == 'R']
print(r_hand)

