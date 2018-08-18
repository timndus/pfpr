for ((  i=0; i<$1; i++  ))
do
	./set_to_all.sh 1700000
	sleep 2
	./set_freq.sh 0 1600000
	./set_freq.sh 1 1800000
	sleep 2
	./set_freq.sh 1 1700000
	./set_freq.sh 2 1800000
	sleep 2
	./set_freq.sh 2 1700000
	./set_freq.sh 3 1800000
	sleep 2

	./set_freq.sh 3 1600000
	./set_freq.sh 2 1800000
	./set_freq.sh 0 1700000
	sleep 2

	./set_freq.sh 1 1800000
	./set_freq.sh 2 1700000
	sleep 2
	
	./set_freq.sh 0 1800000
	./set_freq.sh 1 1700000
	sleep 2

	./set_to_all.sh 1700000
	sleep 2

	./set_to_all.sh 1600000
	sleep 5	
done
