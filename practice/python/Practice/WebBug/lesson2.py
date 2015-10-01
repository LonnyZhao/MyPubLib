#-*-coding:utf-8-*-

import urllib

url = "http://www.iplaypython.com/"

html = urllib.urlopen(url)


code = html.getcode()


if code == 200:
    print html.read()
    print html.info()
else:
    print "404."