# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []
y2 = []

with open('bench_v6_default.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

with open('bench_v6.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))


plt.plot(y1, label='Default')
plt.plot(y1, 'bo')

plt.plot(y2, label='V6')
plt.plot(y2, 'go')


plt.xlabel('x label')
plt.ylabel('Execution Time(Sec)')
plt.title('MPICH ET')
plt.legend()
plt.show()
