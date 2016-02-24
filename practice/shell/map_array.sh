#!/bin/bash
declare -A fruits_value

fruits_value=([apple]='100dollars' [orange]='150 dollars')

echo "Apple cousts ${fruits_value[apple]}"

#display all elem index
echo ${!fruits_value[*]}

#display all elem index other way
echo ${!fruits_value[@]}


