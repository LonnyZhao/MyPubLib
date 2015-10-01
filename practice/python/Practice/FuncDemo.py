#-*-coding:utf-8-*-
'''
python 函数例子
'''
import sys
import random
def Main():
    def F1():
        print "我是F1"
    def F2(x,y):
        a=x+y
        return a
    #定义有多个返回值的函数，用逗号分割不同的返回值
    #返回结果是一个元组
    def F3(x,y):
        a=x/y
        b=x%y
        return a,b
def compareNum(num1,num2):
    if(num1>num2):
        return 1
    elif(num1==num2):
        return 0
    else:
        return -1
#函数的默认参数与返回值
def arithmetic(x=1,y=1,operator="+"):
    result={
        "+":x+y,
        "-":x-y,
        "*":x*y,
        "/":x/y
    }
    return result.get(operator)
if __name__=="__main__":
    Main()
"""
返回多个值例子：
def testList():
    return "aaa","bbb"
a,b=testList()
print a
print b
"""