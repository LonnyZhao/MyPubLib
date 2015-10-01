#-*-coding:utf-8-*-
'''
列表内涵
列表内涵的一般形式如下，我们可以把[]内的列表内涵写为一行，也可以写为多行。
[表达式 for item1 in 序列 1 … for itemN in 序列 N if 条件表达式]
上面的表达式分为三部分，最左边是生成每个元素的表达式，然后是 for 迭代过程，最右边可以设定一个 if
判断作为过滤条件。
'''
__author__ = 'long'
import sys
def func():
    x=1
    y=2
    m=3
    n=4
    sum=lambda x,y,:x+y
    print sum
    sub=lambda m,n:m-n
    print sub
    return sum(x,y)*sub(m,n)

if __name__=="__main__":
    print func()
    #九九乘法表
    s=[(x,y,x*y) for x in range(1,10) for y in range(1,10) if x>=y]
    print s