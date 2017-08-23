import pandas as pd
import numpy as np
countries = ['Russian Fed.', 'Norway', 'Canada', 'United States',
'Netherlands', 'Germany', 'Switzerland', 'Belarus',
'Austria', 'France', 'Poland', 'China', 'Korea', 
'Sweden', 'Czech Republic', 'Slovenia', 'Japan',
'Finland', 'Great Britain', 'Ukraine', 'Slovakia',
'Italy', 'Latvia', 'Australia', 'Croatia', 'Kazakhstan']

gold = [13, 11, 10, 9, 8, 8, 6, 5, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0]
silver = [11, 5, 10, 7, 7, 6, 3, 0, 8, 4, 1, 4, 3, 7, 4, 2, 4, 3, 1, 0, 0, 2, 2, 2, 1, 0]
bronze = [9, 10, 5, 12, 9, 5, 2, 1, 5, 7, 1, 2, 2, 6, 2, 4, 3, 1, 2, 1, 0, 6, 2, 1, 0, 1]


olympic_medal_counts_df = pd.DataFrame({'A Country' : pd.Series(countries),'Gold Medals' : pd.Series(gold), 'Silver Medals' : pd.Series(silver), 'Bronze Medals' : pd.Series(bronze) })
greater_than_one_golds = olympic_medal_counts_df[olympic_medal_counts_df.index < 21]
metals_only = pd.DataFrame({'Gold Medals' : pd.Series(gold), 'Silver Medals' : pd.Series(silver), 'Bronze Medals' : pd.Series(bronze) })
print(olympic_medal_counts_df)
print('===================================')
print(np.mean(greater_than_one_golds['Bronze Medals']))
print('===================================')
avg_medal_count = metals_only.apply(np.mean)
print(avg_medal_count)
#metals_only['Gold Metals'] = metals_only['Gold Metals'].apply(lambda x: x*4)
gold_points = np.dot(metals_only['Gold Medals'], 4)
silver_points = np.dot(metals_only['Silver Medals'], 2)

bronze_points = np.dot(metals_only['Bronze Medals'], 1)

olympic_points_df = pd.DataFrame({'A country_name' : countries, 'points' : gold_points + silver_points + bronze_points })
print(olympic_points_df)