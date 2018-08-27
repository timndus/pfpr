for i in $( cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies );
do
	for j in {1..4}
	do
		sleep 2
		~/msc_project/freq/./set_freq_to_all.sh $i
		mpiexec -bind-to user:0,1,2,3,4,5 -n 6 ./error_effect | tee -a error_effect_$i.log

	done
done
