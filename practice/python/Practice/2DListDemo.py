#-*-coding:utf-8-*-
'''
List使用的基础例程之2维数组定义
'''
__author__ = 'long'
import sys
def Main():
    M=[[1,2,3],[4,5,6],[7,8,9]]
    print M[0]
    print M[1]
    print M[2]
def ColOfLis():
    M=[[1,2,3],[4,5,6],[7,8,9]]
    col2=[row[1] for row in M]
    print col2
    col3=[row[1]+1 for row in M]
    print col3
    colfilter=[row[1] for row in M if row[1]%2==0]
    print colfilter
if __name__=="__main__":
    Main()
    print "提取列的测试\n"
    ColOfLis()