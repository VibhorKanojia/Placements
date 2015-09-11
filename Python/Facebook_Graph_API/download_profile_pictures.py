import requests
import json
import urllib2
token = 'CAACEdEose0cBAEmtnC38syUJum5fGQGcuZAkd7F6CXVSvzC3O6XOc9bXKp2uTrZAQnhBgeZBSYBnatEoTRtz4XhmEmdR1BBgjgSgNFq7ZC1w7RkvWpIewy28ZAkyoj4OJDza3WFtDrpWIBuG44hE4joGu66ooPEZBOuUopuN123NfL658ZBmSmIpKpZA5jtd1r4lol6bFMRx9gZDZD'
api_url = "https://graph.facebook.com/v2.1/"
params = {'access_token':token}
call = "me/friends?fields=picture.width(1000).height(1000).type(large),gender,name"
response = requests.get(api_url+call,params=params)
r = (json.loads(response.content))

for f in r['data']:
  if f['gender'] == 'female':
    p_url = str(f['picture']['data']['url'])
    urlopener1 = urllib2.build_opener()
    page1 = urlopener1.open(p_url)
    my_picture = page1.read()
    filename = f['name']+".jpg"
    fout = open("images/"+filename,"wb")
    fout.write(my_picture)
    fout.close()