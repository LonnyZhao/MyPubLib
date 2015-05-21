#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'
import sys
def Main():
    a=[133,244,2344,2243,22342,224,133,133,989]
    b=set(a)
    print b
def merge():
    a=["11","22","33"]
    b=["11","33"]
    c=set(a)&set(b)
    print c
if __name__=="__main__":
    Main()
    print "merge:"
    merge()

