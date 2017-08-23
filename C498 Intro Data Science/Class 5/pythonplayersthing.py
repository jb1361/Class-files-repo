import pandas as pd

players_dataframe = pd.DataFrame(pd.read_csv('players.csv'))
print(players_dataframe)
print('Number of Players: {0}'.format(players_dataframe.index.max()))
youngest_player_dob = players_dataframe[players_dataframe['birthdate'] == players_dataframe['birthdate'].max()]['name']
print(youngest_player_dob)
print(players_dataframe['country_id'].value_counts().head(1))

