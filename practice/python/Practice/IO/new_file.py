#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'
import sys
import re
if __name__=="__main__":
    #创建文件
    context='''hello world
        hello china'''
    f=file('hello.txt','w')
    f.write(context)
    f.close()
