#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'
import sys
import re
if __name__=="__main__":
    #读取文件
    f=open("hello.txt")
    while True:
        line=f.readline()
        if line:
            print line
        else:
            break
    f.close()
    #一次读取多行的形式
    f=file("hello.txt")
    lines=f.readlines()
    print lines
    for line in lines:
        print line
    #一次性读取所有内容
    f=open("hello.txt")
    context=f.read()
    print context

    #读取前5个字符
    f=open("hello.txt")
    context=f.read(5)
    print context
    print f.tell() #显示当前的位置
    context=f.read(5)
    print context
    print f.tell()
    f.close()
