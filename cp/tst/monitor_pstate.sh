freq_count=$(wc /sys/devices/system/cpu/cpu0/cpufreq/stats/time_in_state | awk '{print $1}')
for i in $(eval echo {1..$1});
do
	var=""
	for j in $(seq 1 $freq_count);
	do
		v_tmp=$(cat /sys/devices/system/cpu/cpu0/cpufreq/stats/time_in_state | awk "NR==$j {print $col}")
		var="${v_tmp},${var}"
		echo $var;
		#echo $j;
	done
done


