#!/bin/bash
#CSV(Comma Separated Value, 逗号分割型数值)

data="name,sex,rollno,location"
oldIFS=$IFS
IFS=,
for item in $data;
do
    echo Item：$item
done
IFS=$oldIFS
