#!/bin/bash

#read -n number_of_chars variable_name
read -n 2 var
echo $var
#non-echoed
read -s var


#显示提示信息
read -p "Enter input:" var

#在限定时间内读取输入
read -t 2 var

#用定界符结束输入行
read -d ":" var
