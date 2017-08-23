
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


conn = sqlite3.connect("flights.db")
df = pd.read_sql_query("select * from airlines limit 5;", conn)
print(df)

cur = conn.cursor()
cur.execute("insert into airlines values(6048,19846,'Test-flight','','',null,null,null,'Y')")
conn.commit()
print(pd.read_sql_query("select * from airlines where id = 19846;", conn))


values = ('USA', '19847')
cur.execute("update airlines set country =? where id=? ", values)
conn.commit()
print(pd.read_sql_query("select * from airlines where id = 19846;", conn))

#values = (19846)
cur.execute("delete from airlines where id = 19846")
conn.commit()
print(pd.read_sql_query("select * from airlines where id = 19846;", conn))
#cur.execute("create table my_daily_flights(id integer, departure date, arrival date, number text, routed integer)")
#conn.commit()

cur.execute("insert into my_daily_flights values(1,'2017-05-18 3:35', '2017-05-19 9:55', 'TI',1)")
conn.commit()
print(pd.read_sql_query("select * from my_daily_flights", conn))

flightdf = pd.DataFrame([[1,datatime(2017,5,17,3,35),datetime(2017,5,19,9,55),'T1',1]],columns = ["id", "departure","arrival","number","route-id"])
flightdf.to_sql("another_daily_flights", conn, if_exists = "replace")
print(pd.read_sql_query("select * from another_daily_flights",conn))

cur.execute("altar table another_daily_flights add column airplanes integer")