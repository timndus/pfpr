while :
do
	sleep 0.5
	cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq >> ~/code/mpich_benchmark/freq_v6.log
done
