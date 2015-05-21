#-*-coding:utf-8-*-
'''
使用python查询文件列表
'''
__author__ = 'long'
import sys
import os
def main():
    sys.stdout.write("Print dir files:\n")
    print os.listdir("c:/")
if __name__=="__main__":
    main()
