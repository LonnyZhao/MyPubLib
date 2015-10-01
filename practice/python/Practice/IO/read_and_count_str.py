#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'
import sys
import os
import re

if __name__=="__main__":
    fl=file("aaa.txt","r")
    count=0
    for s in fl.readlines():
        li=re.findall("hello",s)
        if len(li)>0:
            count=count+li.count("hello")

    print "查找到"+str(count)+"个hello"
    fl.close()