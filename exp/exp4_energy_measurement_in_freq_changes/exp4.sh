for i in $( cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies );
do
	sleep 8
	~/msc_project/freq/./set_freq_to_all.sh $i
done
