#!/bin/bash
for (( j=0; j<269; j++ ))
do
	~/code/rapl/e_read | awk 'NR==15 {print $3}' >> "$1".log
	sleep 2
done
