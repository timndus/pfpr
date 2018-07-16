~/code/freq/./set_to_all.sh 1700000
sleep 10

echo "default"
for (( i = 0; i < 5; i++ )); do
	mpiexec -bind-to user:0,1,2,3 -n 4 ~/code/mpich_benchmark/./stress_all_limit | tail -n 4 | tee -a stress_all_limit.log
	~/code/freq/./set_to_all.sh 1700000
	sleep 10
done

echo "tst4_mode1"
for (( i = 0; i < 5; i++ )); do
	~/code/freq/./set_freq.sh 0 2500000
	mpiexec -bind-to user:0,1,2,3 -n 4 ~/code/mpich_benchmark/./stress_all_limit | tail -n 4 | tee -a stress_all_limit.log
	~/code/freq/./set_to_all.sh 1700000
	sleep 10
done

echo "tst4_mode2"
for (( i = 0; i < 5; i++ )); do
	~/code/freq/./set_freq.sh 0 2500000
	~/code/freq/./set_freq.sh 1 2500000
	mpiexec -bind-to user:0,1,2,3 -n 4 ~/code/mpich_benchmark/./stress_all_limit | tail -n 4 | tee -a stress_all_limit.log
	~/code/freq/./set_to_all.sh 1700000
	sleep 10
done

echo "tst4_mode3"
for (( i = 0; i < 5; i++ )); do
	~/code/freq/./set_freq.sh 0 2500000
	~/code/freq/./set_freq.sh 1 2500000
	~/code/freq/./set_freq.sh 2 2500000
	mpiexec -bind-to user:0,1,2,3 -n 4 ~/code/mpich_benchmark/./stress_all_limit | tail -n 4 | tee -a stress_all_limit.log
	~/code/freq/./set_to_all.sh 1700000
	sleep 10
done

echo "tst4_mode4"
for (( i = 0; i < 5; i++ )); do
	~/code/freq/./set_freq.sh 0 2500000
	~/code/freq/./set_freq.sh 1 2500000
	~/code/freq/./set_freq.sh 2 2500000
	~/code/freq/./set_freq.sh 3 2500000
	mpiexec -bind-to user:0,1,2,3 -n 4 ~/code/mpich_benchmark/./stress_all_limit | tail -n 4 | tee -a stress_all_limit.log
	~/code/freq/./set_to_all.sh 1700000
	sleep 10
done
