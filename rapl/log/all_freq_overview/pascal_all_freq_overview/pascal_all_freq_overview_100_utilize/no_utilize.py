# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []
y2 = []

with open('16_0.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y1.append(float(row[0]))

with open('33_0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

plt.plot(y1, label='1600')
plt.plot(y2, label='3300')

plt.xlabel('Sample number')
plt.ylabel('Power(W)')

## setting the limits on the x-axis and y-axis
#plt.xlim(1,20)
#plt.ylim(0.6,1)

plt.title('')
plt.legend()
#plt.savefig('foo.png', dpi=1500)
plt.show()
