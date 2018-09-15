#!/bin/bash
#executable sample_number log_file_name
for (( j=0; j<$1; j++ ))
do
	var=$(~/msc_project/rapl/e_read_v_1 | awk 'NR==14 {print $3}')
	echo ${var%?} | tee -a $2.log
	#echo ${var%?} >> $2.log
done
