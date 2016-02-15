#!/bin/bash
#add two number
no1=4
no2=5
let result=no1+no2
echo "result=$result"

#self minus
let no1--
#self add
let no2++
echo "no1=$no1"
echo "no2=$no2"

#simplify write method
let no1+=6
echo "no1=$no1"

#other way
#result = $[ no1 + no2 ]
echo "result=$result"

#result = $[ $no1 + 5 ]

#result = $(( $no1 + 50 ))

#result = `expr 4 + 5`

#result = $(expr $no1 + 5)


#all above is only useful for integer op

echo "4 * 0.56" | bc

no=54
result=`echo "$no * 1.5" | bc`
echo $result

#set scale 
echo "scale=2;3/8" | bc

#obase change

no=100
echo "obase=2; $no" | bc

no=1100100
echo "obase=10;ibase=2;$no" | bc

#sqrt

echo "sqrt(100)" | bc
echo "10^10" | bc
