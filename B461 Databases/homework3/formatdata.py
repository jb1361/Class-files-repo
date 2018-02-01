import pandas as pd
import json
import xml
import csv
import xmltodict

inp = str(input())




def open_csv():
	jsonfile = open('parsedjsoncsv.json', 'w')
	jsonfile.write('{"Tweets": ')
	jsonfile.close()
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
		element['UserName'] = element['UserHandle']
		element['UserHandle'] = element['Text']
		element['Text'] = element['Tweet']
		del element['Tweet']
	out = json.dumps([row for row in parsed_json],indent = 4)		
	jsonfile.write(out)
	jsonfile.close()
	jsonfile = open('parsedjsoncsv.json', 'a')
	jsonfile.write('}')
	jsonfile.close()
	
def open_xml():
	#jsonfile = open('parsedjsonxml.json', 'w')
	#jsonfile.write('{"Tweets": ')
	#jsonfile.close()
	
	with open(inp, 'r', encoding="utf8") as f:
		xmlString = f.read()
		
	out = json.dumps(xmltodict.parse(xmlString))
	out = out.replace('null', '""')
	out = out[:-1]
	out = out.replace('"Tweets": {','')
	out = out.replace('"Tweet": [','"Tweets": [')
	
	parsed_json = json.loads(out)
	for element in parsed_json['Tweets']:
		element['ID'] = int(element['ID'])
		element['QuotedID'] = int(element['QuotedID'])
		element['Retweets'] = int(element['Retweets'])   
	out = json.dumps(parsed_json,indent = 4)		
	
	jsonfile = open('parsedjsonxml.json', 'w')
	jsonfile.write(out)
	jsonfile.close()

	
if 'csv' in inp:
	open_csv()
elif 'xml' in inp:
	open_xml()
else:
	print('Input correct file type. (csv or xml)')
	
