# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y1 = []
y2 = []

with open('overhead.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

with open('default.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

plt.plot(y2, label='overhead')
plt.plot(y1, label='default')

plt.xlabel('Sample Number')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
#plt.xticks(np.arange(0, 20, 3))
#plt.yticks(np.arange(65, 86, 5))
plt.legend()
#plt.savefig('pfpr_nemesis_17_12_execution_time.png', dpi=500)
plt.show()
