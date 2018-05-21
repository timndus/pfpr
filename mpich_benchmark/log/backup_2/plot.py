# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []
y2 = []
y3 = []
y4 = []

with open('execution_time_default.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

with open('execution_time_v2.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

with open('execution_time_v3.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y3.append(float(row[0]))

with open('execution_time_v4.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y4.append(float(row[0]))



plt.plot(y1, label='Default')
plt.plot(y1, 'bo')

plt.plot(y2, label='V2')
plt.plot(y2, 'go')

plt.plot(y3, label='V3')
plt.plot(y3, 'ro')

plt.plot(y4, label='V4')
plt.plot(y4, 'bo')


plt.xlabel('x label')
plt.ylabel('Execution Time(Sec)')
plt.title('MPICH ET')
plt.legend()
plt.show()
