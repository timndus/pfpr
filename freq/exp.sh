for i in {1..64}
do
	sleep 2
	mpiexec -bind-to user:0,1 -n 2 /home/timndus/code/mpich_benchmark/./a.out
done
