#-*-coding:utf-8-*-
'''
set类型使用实例
'''
__author__ = 'long'
if __name__=="__main__":
    #使用writelines()写文件
    f=file("hello.txt","w+")
    li=["hello chu888 楚\n","hello li\n"]
    f.writelines(li)
    f.close()
    #追加文件内容
    f=file("hello.txt","a+")
    new_context="goodbye"
    f.write(new_context)
    f.close()
