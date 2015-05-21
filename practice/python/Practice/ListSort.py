#-*-coding:utf-8-*-
'''
List使用的基础例程之排序操作
'''
__author__ = 'long'
import sys
def Main():
    array=[5,2,3,1,8]
    array.sort()
    for s in array:
        print s

    array.reverse()
    for s in array:
        print s


if __name__=="__main__":
    Main()