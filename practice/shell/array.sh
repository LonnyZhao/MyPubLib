#!/bin/bash
#define a array
array_var=(1 2 3 4 5 6 7 8)

array_var2[0]="test1"
array_var2[1]="test2"
array_var2[2]="test3"
array_var2[3]="test4"


#printf element in array
echo ${array_var[0]}

index=4
echo ${array_var[$index]}


#printf all 
echo ${array_var[*]}

echo ${array_var[@]}


#printf len of array
echo ${#array_var2[*]}

