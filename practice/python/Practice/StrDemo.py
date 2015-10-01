#-*-coding:utf-8-*-
'''
字符串使用实例
'''
__author__ = 'long'
import sys
def Main():
    sys.stdout.write("开始程序\n")
    str1='i am "python"\n'
    str2="i am 'python'\r"
    str3="""
         i'm "Python",
        <a href="http://www.baidu.com"></a>
        """
    print str1,str2,str3
def UnicodeDemo():
    print u"我是派森"
#当使用 UTF-8 编码时，非 unicode 字符中一个汉字的长度是 3，而使用 gb2312 时是 2，
def UnicodeLenDemo():
    unicode = u'我'
    str='我'
    #输出1,3
    print len(unicode),len(str)
if __name__=="__main__":
    Main()
    UnicodeDemo()
    UnicodeLenDemo()