for (( i=1; i<$1; i++ ))
do
	sleep 2
	mpiexec -bind-to user:0,1,2,3 -n 4 ./a.out | tail -n 1 | tee -a $2.log
done
