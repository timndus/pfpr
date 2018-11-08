# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y1 = []
y2 = []
y3 = []

with open('nemesis/nemesis_4.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))


with open('sock/sock_4.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

with open('pfpr/pfpr_4.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y3.append(float(row[0]))

plt.plot(y1, label='default_nemesis_repeat_4')
plt.plot(y2, label='default_sock_repeat_4')
plt.plot(y3, label='pfpr_nemesis_repeat_4')

plt.xlabel('Sample Number')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
#plt.xticks(np.arange(0, 20, 3))
#plt.yticks(np.arange(18.48, 18.49, 0.001))
plt.legend()
plt.savefig('default_nemesis_vs_sock_vs_pfpr_repeat_4.png', dpi=500)
plt.show()
