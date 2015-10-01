#-*-coding:utf-8-*-
'''
python 函数例子
'''
import sys
def Main():
    class A:
        def __init__(self):
            self.x=1

    a=A()
    print a.x
class Student:
    def __init__(self,name,age):
        self.__name=name
        self.__age=age
    def getName(self):
        format="my name is %s my age is %d"%(self.__name,self.__age)
        print format
    def __del__(self):
        print "del"

class A:
    #定义静态成员变量
    y=2
    def __init__(self):
        #定义公共的成员变量
        self.x=1
        #定义私有的成员变量
        self.__z=1
if __name__=="__main__":
    Main()
    student=Student("chu",35)
    student.getName()
    a=A()
    #打印公共成员变量
    print a.x
    #打印静态成员变量
    print A.y
    #打印私有成员变量出错
    #print a.__z

