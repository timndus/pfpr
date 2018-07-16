# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []

with open('stress_all_limit_v1.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))


plt.plot(y1, label='Default')
plt.plot(y1, 'bo')


plt.xlabel('sampel number')
plt.ylabel('Execution Time(Sec)')
plt.title('MPICH ET')
plt.legend()
plt.show()
