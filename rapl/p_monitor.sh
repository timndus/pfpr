#!/bin/bash
for (( j=0; j<128; j++ ))
do
	~/code/rapl/e_read | awk 'NR==15 {print $3}' >> "$1".log
done
