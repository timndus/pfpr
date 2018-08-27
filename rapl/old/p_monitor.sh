#!/bin/bash
for (( j=0; j<$1; j++ ))
do
	var=$(./e_read | awk 'NR==15 {print $3}')
	echo ${var%?} | tee -a $2.log
done
