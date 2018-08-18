while (($#)); do
	echo userspace > /sys/devices/system/cpu/cpu$1/cpufreq/scaling_governor
	echo $2 > /sys/devices/system/cpu/cpu$1/cpufreq/scaling_max_freq
	shift 2
done
