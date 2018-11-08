# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y1 = []
y6 = []

with open('nemesis/nemesis_64.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))


with open('sock/sock_64.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y6.append(float(row[0]))

plt.plot(y1, label='default_nemesis_repeat_64')
plt.plot(y6, label='default_sock_repeat_64')

plt.xlabel('Sample Number')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
#plt.xticks(np.arange(0, 20, 3))
#plt.yticks(np.arange(18.48, 18.49, 0.001))
plt.legend()
plt.savefig('default_nemesis_vs_sock_repeat_64.png', dpi=500)
plt.show()
