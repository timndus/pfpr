#exp_bench8_overhead repeat logfilename
for (( i=0; i<$1; i++ ))
do
	mpiexec -bind-to user:0,1,2,3,4,5 -n 6 ~/msc_project/mpich_benchmark/bench_v8_overhead/./bench_v8_overhead | awk '{print $2}' >> $2.log
done
