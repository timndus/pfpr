#!/bin/bash
for (( j=0; j<128; j++ ))
do
	var=$(~/code/rapl/e_read | awk 'NR==15 {print $3}')
	echo ${var%?} | tee -a $1.log
done
