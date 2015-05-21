#-*-coding:utf-8-*-

import urllib
#查看帮助
#print help(urllib)
url="http://www.iplaypython.com/"
html=urllib.urlopen(url)

#需要注意在meta中charset是否为utf-8,如果不是则需要转换
#例如gb2312
print html.read().decode("gbk").encode("utf-8")

#第一步获取网页头部信息
print html.info()
#另外需要知道网页的状态码
#只有为200的状态码才是正确的
"""
网页状态码含义：
200表示可以正常访问，此时可以抓取
301重定向（永久）
302临时重定向
404网页不存在
403禁止访问
500 服务器忙，服务器无响应
《HTTP权威指南》中比较详细
"""
print html.getcode()
#获取传入的url情况
print html.geturl()

#使用完成后需要关闭
html.close()

#网页抓取完后，下载网页的方式
urllib.urlretrieve(url,"c:\\Users\\Leo\\Desktop\\abc.txt")


