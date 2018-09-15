# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y1 = []

with open('17.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

plt.plot(y1, label='default_nemesis_power')

plt.xlabel('Execution Time (ms/100)')
plt.ylabel('Power (w)')
ax.grid(which='both')
plt.xticks(np.arange(0, 850, 100))
plt.yticks(np.arange(55, 95, 5))
#plt.title('default_nemesis vs. default_sock vs. pfpr_nemesis_17_12 vs. pfpr_sock_17')
plt.legend()
plt.savefig('exp7_default_nemesis_power.png', dpi=500)
plt.show()
