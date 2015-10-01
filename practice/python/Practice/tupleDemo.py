#-*-coding:utf-8-*-
'''
元组类型使用实例
'''
__author__ = 'long'
import sys
if __name__=="__main__":
    tuple_name=("apple","banana","grape","orange")
    print tuple_name[0]
    #分片输出功能
    print tuple_name[-1]
    print tuple_name[-2]
    print tuple_name[1:3]

    print '-----------------------'
    tuple=(('t1','t2'),('t3','t4'))
    print tuple[0][0]
    print tuple[1][0]
    #使用元组实现解包
    a,b,c,d=tuple_name
    print a,b,c,d



