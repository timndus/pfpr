# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []

with open('tst_me.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y1.append(float(row[0]))


plt.plot(y1, label='bench_v6_default_mpi')

plt.xlabel('Sample number')
plt.ylabel('Power(W)')

## setting the limits on the x-axis and y-axis
#plt.xlim(1,20)
#plt.ylim(0.6,1)

plt.title('')
plt.legend()
plt.savefig('me.png', dpi=500)
plt.show()
