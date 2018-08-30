# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y1 = []

with open('exp8_pfpr_sock_17_execution_time.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

plt.plot(y1, 'o', label='pfpr_sock_17_execution_time')

plt.xlabel('Sample Number')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
plt.xticks(np.arange(0, 20, 3))
plt.yticks(np.arange(65, 86, 5))
plt.legend()
plt.savefig('exp8_pfpr_sock_17_execution_time.png', dpi=500)
plt.show()
