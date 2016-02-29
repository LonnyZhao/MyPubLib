#!/bin/bash
#for

for var in list;
do
    commands;
done


for i in {a..z};
do actions
done


#c style

for((i=0;i<10;i++))
{
        commands $i;
}

while condition
do
    commands
done


#until

x=0;
until [ $x -eq 9 ];
do let x++; echo $x;
done
