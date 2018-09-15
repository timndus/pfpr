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
y6 = []
y7 = []
y8 = []
y9 = []

with open('0state0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y0.append(float(row[0]))

with open('0state1.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

with open('0state2.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y2.append(float(row[0]))

with open('0state3.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y3.append(float(row[0]))

with open('0state4.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y4.append(float(row[0]))
########################################################

with open('1state0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y5.append(float(row[0]))

with open('1state1.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y6.append(float(row[0]))

with open('1state2.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y7.append(float(row[0]))

with open('1state3.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y8.append(float(row[0]))

with open('1state4.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y9.append(float(row[0]))

plt.plot(y0, label='0state0')
plt.plot(y1, label='0state1')
plt.plot(y2, label='0state2')
plt.plot(y3, label='0state3')
plt.plot(y4, 'o', label='0state4')

plt.plot(y5, label='1state0')
plt.plot(y6, label='2state1')
plt.plot(y7, label='3state2')
plt.plot(y8, label='4state3')
plt.plot(y9, '^', label='5state4')

plt.xlabel('Sample Number')
plt.ylabel('Usage')
ax.grid(which='both')
#plt.xticks(np.arange(0, 20, 3))
#plt.yticks(np.arange(65, 86, 5))
plt.legend()
#plt.savefig('pfpr_nemesis_17_12_execution_time.png', dpi=500)
plt.show()
