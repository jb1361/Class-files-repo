import json
import requests
url = 'http://ws.audioscrobbler.com/2.0/?method=album.getinfo&api_key=4005c05d541d9a056136d5450be12883&artist=Rihanna&album=Loud&format=json'
data = requests.get(url).text
data = json.loads(data)
print(data)
print('Readable: ', json.dumps(data,indent = 4))
print(data['album']['listeners'])

#find top artist in spain and number of listeners
url2 = 'http://ws.audioscrobbler.com/2.0/?method=geo.gettopartists&country=Spain&api_key=4005c05d541d9a056136d5450be12883&format=json'
data2 = requests.get(url2).text
data2 = json.loads(data2)

print('Readable: ', json.dumps(data2,indent = 4))
print(json.dumps(data2['topartists']['artist'][0],indent = 4))
