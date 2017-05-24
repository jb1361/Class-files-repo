
import pandas as pd
import sqlite3


con = sqlite3.connect("flights.db")
cur = con.cursor()
con.execute("SELECT * from airlines limit 5;")
results = cur.fetchall()
print(results)
cur.execute("SELECT name,city from airports group by country")
airports = cur.fetchall()
print(airports)
dfl = pd.read_sql_query("select * from routes limit 5", con)
print(dfl)
cur.close()
con.close()