#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'
import sys
import os
if __name__=="__main__":
    li=os.listdir(".")
    print li
    if "hello.txt" in li:
        os.rename("hello.txt","hi.txt")
    elif "hi.txt" in li:
        os.rename("hi.txt","hello.txt")

    #把后缀为html的改为htm后缀的文件

    files=os.listdir(".")
    for filename in files:
        #查找文件名中.所在位置并把它给pos
        pos=filename.find(".")
        #得到后面的内容
        if filename[pos+1:]=="html":
            print filename
            newname=filename[:pos+1]+"htm"
            print newname
    #another way
    files=os.listdir(".")
    for filename in files:
        li=os.path.splitext(filename)
        if li[1]==".html":
            newname=li[0]+".htm"
            os.rename(filename,newname)
