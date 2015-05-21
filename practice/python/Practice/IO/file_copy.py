#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'
import sys
import re
import os
import shutil

if __name__=="__main__":
    shutil.copyfile("a.txt","hello2.txt")
    shutil.move("a.txt","../")
    shutil.move("hello2.txt","aaa.txt")
