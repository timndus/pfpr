for ((  i=0; i<$1; i++  ))
do
	./set_to_all.sh 1600000
	sleep 10

	./set_to_all.sh 1600000
	sleep 10
	
	./set_to_all.sh 1700000
	sleep 5

	./set_freq.sh 1 1800000
	sleep 5




	./set_to_all.sh 1600000
	sleep 10

	./set_to_all.sh 1700000
	sleep 5

	./set_freq.sh 0 1600000
	sleep 5




	./set_to_all.sh 1600000
	sleep 10
	
	./set_to_all.sh 1700000
	sleep 5

	./set_freq.sh 0 1600000
	./set_freq.sh 1 1900000
	sleep 5

	

	./set_to_all.sh 1600000
	sleep 10

	./set_to_all.sh 1700000
	sleep 5

	./set_freq.sh 0 1600000
	./set_freq.sh 1 1800000
	./set_freq.sh 2 1800000
	sleep 5
done
