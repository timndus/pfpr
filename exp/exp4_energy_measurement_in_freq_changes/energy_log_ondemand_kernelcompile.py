# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []

with open('energy_log_ondemand_kernelcompile.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

plt.plot(y1, label='energy_log_ondemand_kernelcompile')
plt.plot(y1, 'o')

plt.xlabel('x label')
plt.ylabel('Energy')
plt.title('MPICH Energy')
plt.legend()
plt.show()
