for i in $( cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies );
do
	for j in {1..16}
	do
		sleep 2
		~/code/freq/./set_to_all.sh $i
		mpiexec -bind-to user:0,1,2,3 -n 4 ./a.out | tail -n 1 | tee -a bench_v6_pascal_$i.log

	done
done
