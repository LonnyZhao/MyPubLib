#-*-coding:utf-8-*-
'''
python module使用例子
'''
__author__ = 'long'
import sys
import define
#直接导入myvar变量可以使用
#from define import myvar
def Main():
    print define.myvar
    #输出所有可以使用的变量
    print dir(define)
    print define.__file__
if __name__=="__main__":
    Main()
