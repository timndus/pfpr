#!/bin/bash
for (( j=0; j<$1; j++ ))
do
	var=$(~/code/rapl/e_read_v_1 | awk 'NR==15 {print $3}')
	echo ${var%?} | tee -a $2.log
	#echo ${var%?} >> $2.log
done
