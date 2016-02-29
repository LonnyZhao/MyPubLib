#!/bin/bash

if condition;
then
    commands
fi


if condition;
thencommands;
elif condition;
then
    commands
else
    commands
fi

[ condition ] && action; #如果condition为真,则执行action
[ condition ] || action; #如果condition为假，则执行action


#eq:相等
#ne:非零
#gt:大于
#lt:小于
#ge:大于或等于
#le:小于或等于


[ $var1 -ne 0 -a $var2 -gt 2 ] #使用逻辑与-a
[ $var -ne 0 -o var2 -gt 2 ]


#文件相关

[ -f $file_var ] #若果给定的变量包含正常的文件路径或文件名,则返回真
[ -x $var ] #如果给定的变量包含的文件可执行，则返回真
[ -d $var ] #如果给定的变量包含的是目录，则返回真
[ -e $var ] #如果给定的变量包含的文件存在，则返回真
[ -c $var ] #如果给定的变量包含的是一个字符设备文件的路径，则返回真
[ -b $var ] #如果给定的变量包含的是一个块设备文件的路径，则返回真
[ -w $var ] #是否可写
[ -r $var ] #是否可读
[ -L $var ] #符号链接

#demo
fpath="/etc/passwd"
if [ -e $fpath ]; then
    echo File exists
else
    echo Does not exists
fi

