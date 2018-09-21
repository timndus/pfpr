# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y4 = []
y9 = []

with open('nemesis/default_nemesis_repeat_16.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y4.append(float(row[0]))

with open('sock/default_sock_repeat_16.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y9.append(float(row[0]))

plt.plot(y4, label='default_nemesis_repeat_16')
plt.plot(y9, label='default_sock_repeat_16')

plt.xlabel('Sample Number')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
#plt.xticks(np.arange(0, 20, 3))
#plt.yticks(np.arange(65, 86, 5))
plt.legend()
plt.savefig('default_repeat_16.png', dpi=500)
plt.show()
