import pandas as pd
import json
import xml
import csv



inp = str(input())


jsonfile = open('parsedjsoncsv.json', 'w')
jsonfile.write('{"Tweets": ')
jsonfile.close()

def open_csv():
	csvf = open(inp, encoding="utf8")
	jsonfile = open('parsedjsoncsv.json', 'a')
	fields = ('Tweet','ID','QuotedID','RetweetedHandle','RetweetedName','RetweetedText','Retweets','Source','Text','UserHandle','UserName')
	reader = csv.DictReader(csvf, fields)
	out = json.dumps([row for row in reader])
	parsed_json = json.loads(out)
	for element in parsed_json:
		element['ID'] = int(element['ID'])
		element['QuotedID'] = int(element['QuotedID'])
		element['Retweets'] = int(element['Retweets'])    
		del element['Tweet']
	out = json.dumps([row for row in parsed_json])		
	jsonfile.write(out)
	jsonfile.close()
	print(out)
	
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