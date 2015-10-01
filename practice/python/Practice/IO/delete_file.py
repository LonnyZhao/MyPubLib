#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'

import sys
import re
import os
if __name__=="__main__":
    file("hello.txt","w")
    if os.path.exits("hello.txt"):
        os.remove("hello.txt")
