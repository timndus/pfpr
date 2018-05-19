#!/bin/bash
echo > log
x=1
while [ $x -le 1000 ]
do
  cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq >> freq_0.log
   echo $(($(date +%S%N)/10000)) >> time_0.log
  #date +%s%N >> time_0.log
  cat /sys/devices/system/cpu/cpu1/cpufreq/scaling_cur_freq >> freq_1.log
   echo $(($(date +%S%N)/10000)) >> time_1.log
  #date +%s%N >> time_1.log
  cat /sys/devices/system/cpu/cpu2/cpufreq/scaling_cur_freq >> freq_2.log
   echo $(($(date +%S%N)/10000)) >> time_2.log
  #date +%s%N >> time_2.log
  cat /sys/devices/system/cpu/cpu3/cpufreq/scaling_cur_freq >> freq_3.log
   echo $(($(date +%S%N)/10000)) >> time_3.log
  #date +%s%N >> time_3.log
  x=$(( $x + 1 ))
done
