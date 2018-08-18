for ((  i=0; i<$1; i++  ))
do
	echo "waiting to start test $i"
	~/code/freq/./set_to_all.sh 1600000
	sleep 10

	echo "start, test $i"
	~/code/freq/./set_to_all.sh 1700000
	sleep 10

	~/code/freq/./set_freq.sh 0 1800000
	sleep 10

	~/code/freq/./set_freq.sh 1 1800000
	sleep 10

	~/code/freq/./set_freq.sh 2 1800000
	sleep 10

	~/code/freq/./set_freq.sh 3 1800000
	sleep 10
	
	~/code/freq/./set_to_all.sh 1600000

	echo "end, test $i"
done
