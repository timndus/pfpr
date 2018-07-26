cpu_count=$(nproc)
while true;
do
	clear
	for (( i=0; i<cpu_count; i++ ))
	do
		echo -n -e "[$i]: \t"; cat /sys/devices/system/cpu/cpu$i/cpufreq/scaling_cur_freq
	done
	sleep 0.5
done
