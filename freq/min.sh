#!/bin/bash
cpu_count=$(nproc)
for (( i=0; i<cpu_count; i++ ))
do
	echo userspace > /sys/devices/system/cpu/cpu$i/cpufreq/scaling_governor
	cat /sys/devices/system/cpu/cpu$i/cpufreq/scaling_min_freq  > /sys/devices/system/cpu/cpu$i/cpufreq/scaling_setspeed
done
