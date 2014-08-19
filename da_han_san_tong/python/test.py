## -*- coding: utf-8 _*_
import requests
import urllib2
#payload = {'Account': 'dh20891', 'Pa\
#ssword': 'daffacc5d5b2482ab603715a6d68566\
#d', 'Phones': '123456789\
#9', 'Content': u"1.2.4.8的外网异常，已重置该接口，请密切关注".encode('utf-8')}
#headers = {'Content-type': 'charset=utf-8'}
payload = {'message':
           """<?xml version='1.0' encoding='UTF-8'?>
           <message><account>dh20891</account>
           <password>1231234</password>
           <msgid></msgid><phones>123456789</phones>
           <content>1.2.4.8的外网异常</content>
           <sign></sign><subcode></subcode><sendtime></sendtime></message>
           """}
r = requests.post('http://3tong.net/http/sms/Submit\
', params=payload)
# headers=headers)
#r = requests.get('http://3tong.net/http/SendSms', params=payload)
#print xml
print(r.url)
print r.encoding
print r.text
