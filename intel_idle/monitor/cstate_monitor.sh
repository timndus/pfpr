#!/bin/bash
core_count=$(nproc)
dir=/sys/devices/system/cpu/cpu0/cpuidle/
state_list=$(ls $dir)
while true
do
	for (( i=0; i<$core_count; i++))
	do
		for state in $state_list
		do
			cat $dir$state'/usage' >> $i$state.log
		done
	done
done
