import pandas as pd
import json
import xml




inp = str(input())

jsonfile = open('parsedjsoncsv.json', 'w')
jsonfile.write('{"Tweets": ')
jsonfile.close()

def open_csv():
	df = pd.DataFrame(pd.read_csv(inp))
	out = df.to_json(orient='records')
	j = json.dumps(out,indent = 4)
		
	jsonfile = open('parsedjsoncsv.json', 'a')
	jsonfile.write(j)
	jsonfile.close()
	
	#csvf = open(inp, encoding="utf8")
	#jsonfile = open('parsedjsoncsv.json', 'w')
	#fields = ('ID','QuotedID','RetweetedHandle','RetweetedName','RetweetedText','Retweets','Source','Text','UserHandle','UserName')
	#reader = csv.DictReader(csvf, fields)
	#for i in reader:
		#json.dump(i, jsonfile,indent = 4,separators=(',', ': '))
		
	#	jsonfile.write(',')
	#	jsonfile.write('\n')
	
def open_xml():
	return 0
	
if 'csv' in inp:
	open_csv()
elif 'xml' in inp:
	open_xml()
else:
	print('Input correct file type. (csv or xml)')
	
jsonfile = open('parsedjsoncsv.json', 'a')
jsonfile.write('}')
jsonfile.close()