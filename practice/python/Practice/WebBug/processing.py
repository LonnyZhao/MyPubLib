#-*-coding:utf-8-*-

import urllib


"""
@pram1 传入网址，网址的类型一定是字符串
@pram2 传入的，本地的网页保存路径+文件名
@pram3 一个函数的调用，可以任意定义该函数的行为，该函数应有3个参数（到目前为止传递的数据块数量，每个数据块的大小，单位为byte,远程文件的大小（有时候会返回-1））
"""
def callback(pNum,pSzie,fileSize):
   download_prgress =  100.0*pNum*pSzie/fileSize

   if download_prgress > 100:
       download_prgress = 100
   print "%.2f%%" %download_prgress,

url = "http://www.iplaypython.com"
urllib.urlretrieve(url,"C:\\iplaypython.html",callback)

#头部信息中有远程文件的大小Content-Length
print urllib.urlopen(url).info()
