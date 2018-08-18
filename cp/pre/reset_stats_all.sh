cpu_count=$(nproc)
for (( i=0; i<cpu_count; i++ ))
do
	sudo echo 1 > /sys/devices/system/cpu/cpu$i/cpufreq/stats/reset
done
