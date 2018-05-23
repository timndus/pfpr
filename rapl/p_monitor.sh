#!/bin/bash
~/code/freq/./set_to_all.sh "$1" 
for (( j=0; j<20; j++ ))
do
	~/code/rapl/rapl-read | awk 'NR==15 {print $3}' >> ~/code/rapl/log/e_"$1"_no.log
	sleep 2
done
