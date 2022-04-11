from urllib import request

url = 'https://t.bilibili.com'
header = {
    'User-Agent':    "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:99.0) Gecko/20100101 Firefox/99.0"}
req = request.Request(url=url, headers=header)

response = request.urlopen(req)
string = response.read().decode('utf-8')

def save_to_file(file_name, contents):
    fh = open(file_name, 'w')
    fh.write(contents)
    fh.close()

save_to_file('bili.html', string)
