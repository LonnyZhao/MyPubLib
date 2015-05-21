#-*-coding:utf-8-*-
'''
正则表达式使用例子
'''
__author__ = 'long'
#第一步引入正则表达式的包
import re
#构建正则表达式对象
regex=re.compile('[a-z]{10}')
#根据正则式在指定数据中检索匹配项，如果匹配，IsMatch方法就会返回true
m1=re.match(regex,'1234567890')
m2=re.match(regex,'abcdefghig')
if m1 is not None:
    print 'True'
if m2 is not None:
    print 'True'
