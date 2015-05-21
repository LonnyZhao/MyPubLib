#-*-coding:utf-8-*-
'''
字典类型使用实例
'''
__author__ = 'long'
import sys
if __name__=="__main__":
    dict={"a":"apple","b":"banana","g":"grape","o":"orange"}
    print dict
    print dict["a"]
    dict2={1:"apple",2:"banana",3:"grape",4:"orange"}
    print dict2
    #字典的添加、删除、修改操作
    dict["w"]="watermelon"
    print dict
    del(dict["a"])

    print dict
    print dict.pop("b")

    #字典的遍历
    for k in dict:
        print "dict[%s]="%k,dict[k]

    #字典的keys与values方法
    print dict.keys()
    print dict.values()
    #字典的使用实例
    D={"food":"spam","quantity":4,"color":"pink"}
    print D["food"]
    D["quantity"]+=1
    print D


    #另外一种定义字典的方法
    D={}
    D["name"]="Bob"
    D["job"]="dev"
    D["age"]=40
    print D
    #使用键值进行排序
    D={"a":1,"b":2,"c":3}
    print D
    Ks=D.keys()
    print Ks
    Ks.sort()
    print Ks
    for key in Ks:
        print key,"=>",D[key]

    for key in sorted(D):
        print key,"=>",D[key]

    #迭代与优化
    squares=[x**2 for x in [1,2,3,4,5]]
    print squares

    #等效于
    squares=[]
    for x in [1,2,3,4,5]:
        squares.append(x**2)

    #测试键值是否存在
    D={"food":"spam","quantity":4,"color":"pink"}
    #测试不存在的键值
    if not D.has_key('f'):
        print '不存在这个键值'
    else:
        print D['f']

