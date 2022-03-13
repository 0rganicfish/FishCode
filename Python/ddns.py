import os
import re
import socket
from aliyunsdkcore.client import AcsClient
from aliyunsdkcore.request import CommonRequest
import json

# 初始化
client = AcsClient('LTAI5t6JJ1hT8tPe21osxubc',
                   'h4b1WcgMe4Yc1Frr9luIim2x2ggPuP', 'cn-hangzhou')
request = CommonRequest()
request.set_domain('alidns.aliyuncs.com')
request.set_version('2015-01-09')
domain = "organicfish.top"
prefix = "www"
ip = []

# ipv6

output = os.popen("ipconfig /all").read()
result = re.findall(r"(([a-f0-9]{1,4}:){7}[a-f0-9]{1,4})", output, re.I)
ip.append(result[0][0])
print("现在的 ipv6地址为：", ip[0])


# 获取本机IPv4地址
ip.append(socket.gethostbyname(socket.gethostname()))
print("现在的 ipv4 地址为：", ip[1])

# 获取二级域名的RecordId
request.set_action_name('DescribeDomainRecords')
request.add_query_param('DomainName', domain)
response = client.do_action_with_exception(request)
jsonObj = json.loads(response.decode("UTF-8"))
records = jsonObj["DomainRecords"]["Record"]
flag = False

if records[0]['Value'] == ip[0]:
    print("ipv6 记录已为最新")
    flag = True
if records[1]['Value'] == ip[1]:
    print("ipv4 记录已为最新")
    flag = True
if flag:
    exit()

# 更新IP记录
request.set_action_name('UpdateDomainRecord')
request.add_query_param('RecordId', records[0]['RecordId'])
request.add_query_param('RR', prefix)
request.add_query_param('Type', 'AAAA')
request.add_query_param('Value', ip[0])

request.add_query_param('RecordId', records[0]['RecordId'])
request.add_query_param('RR', prefix)
request.add_query_param('Type', 'A')
request.add_query_param('Value', ip[1])

response = client.do_action_with_exception(request)
print("DDNS更新完成\n")
