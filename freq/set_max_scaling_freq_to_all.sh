#!/bin/bash
cpu_count=$(nproc)
for (( i=0; i<cpu_count; i++ ))
do
	echo $1  > /sys/devices/system/cpu/cpu$i/cpufreq/scaling_max_freq
done
