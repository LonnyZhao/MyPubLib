#-*-coding:utf-8-*-

# import urllib
#
# url = "http://www.tudou.com"
#
# info = urllib.urlopen(url).info()
# print info
# print info.getparam("charset")


import urllib
import chardet #字符集检测

#chardet获取编码的方式，返回map
#confidence概率值
#encoding:类型
# url = "http://www.amazon.cn"
# content = urllib.urlopen(url).read()
#
# result =  chardet.detect(content)
# print result["encoding"]
#---------------------------------------------

#封装
def automatic_detect(url):
    content = urllib.urlopen(url).read()
    result = chardet.detect(content)
    encoding = result['encoding']
    return encoding
urls = ["http://www.iplaypython.com",
        "http://www.baidu.com",
      "http://www.163.com",
      "http://www.jd.com",
      "http://www.dangdang.com",
      "http://www.tudou.com"]


for url in urls:
    print url,automatic_detect(url)


