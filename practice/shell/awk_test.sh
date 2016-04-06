#!/bin/bash

while read line;
do 
    rm_obj=$(echo  $line | awk '{ print  $2 }')
    #echo $rm_obj
    if [ -f $rm_obj ];then
        #echo "This is a file"
        rm $rm_obj
    elif [ -d $rm_obj  ];then
        #echo "This is a dir"
        rm -r $rm_obj
    fi
done<rm.txt
