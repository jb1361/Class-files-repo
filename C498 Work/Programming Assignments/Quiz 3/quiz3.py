import pandas as pd
import numpy as np

df = pd.DataFrame(pd.read_csv('master.csv'))
print(pd.isnull(df['height']))
height_df = pd.DataFrame(df['height'])
height_df = height_df.fillna(height_df.mean())
print(height_df)
