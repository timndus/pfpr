#!/bin/bash
sudo chmod 444 /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq
sudo chmod 646 /sys/devices/system/cpu/cpu*/cpufreq/scaling_max_freq
sudo chmod 646 /sys/devices/system/cpu/cpu*/cpufreq/scaling_min_freq
sudo chmod 646 /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
sudo chmod 646 /sys/devices/system/cpu/cpu*/cpufreq/scaling_setspeed
cpu_count=$(nproc)
for (( i=0; i<cpu_count; i++ ))
do
	echo $1  > /sys/devices/system/cpu/cpu$i/cpufreq/scaling_max_freq
done
