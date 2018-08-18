# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y0 = []
y1 = []
y2 = []
y3 = []
c = 0

with open('freq_v6.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
    	if c % 4 == 0:
        	y0.append(float(row[0]))
        elif c % 4 == 1:
        	y1.append(float(row[0]))
    	elif c % 4 == 2:
    		y2.append(float(row[0]))
    	elif c % 4 == 3:
    		y3.append(float(row[0]))
    	c = c + 1

plt.plot(y0, label='Core 0')
plt.plot(y0)

plt.plot(y1, label='Core 1')
plt.plot(y1)

plt.plot(y2, label='Core 2')
plt.plot(y2)

plt.plot(y3, label='Core 3')
plt.plot(y3)

plt.xlabel('x label')
plt.ylabel('Execution Time(Sec)')
plt.title('MPICH ET')
plt.legend()
plt.show()
