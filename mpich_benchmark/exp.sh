for i in {1..16}
do
	sleep 2
	mpiexec -bind-to user:0,1,2,3 -n 4 ./a.out | tail -n 1 | tee -a bench_v6.log
done
