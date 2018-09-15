# Import the necessary packages and modules
import glob, os

import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y0 = []
y1 = []
y2 = []
y3 = []
y4 = []
y5 = []

with open('0state0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y0.append(float(row[0]))

with open('1state0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

with open('2state0.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y2.append(float(row[0]))

with open('3state0.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y3.append(float(row[0]))

with open('4state0.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y4.append(float(row[0]))

with open('5state0.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y5.append(float(row[0]))

plt.plot(y0, label='0state0')
plt.plot(y1, label='1state0')
plt.plot(y2, label='2state0')
plt.plot(y3, label='3state0')
plt.plot(y4, label='4state0')
plt.plot(y5, label='5state0')

plt.xlabel('Sample Number')
plt.ylabel('Usage')
ax.grid(which='both')
#plt.xticks(np.arange(0, 20, 3))
#plt.yticks(np.arange(65, 86, 5))
plt.legend()
#plt.savefig('pfpr_nemesis_17_12_execution_time.png', dpi=500)
plt.show()
