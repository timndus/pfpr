#!/bin/bash
#executable sample_number log_file_name
for (( j=0; j<$1; j++ ))
do
	var=$(./e_read_v_1 | awk 'NR==14 {print $3}')
	#var=$(./e_read_v_1 | awk 'NR==14')
	#echo ${var%?} | tee -a $2.log
	echo ${var%?} >> $2.log
done
