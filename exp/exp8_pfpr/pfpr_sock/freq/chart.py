# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y1 = []

for i in range(0, 117):
    y1.append(10.2)

for i in range(0, 64):
    y1.append(10.1)

for i in range(0, 466):
    y1.append(10.2)

for i in range(0, 64):
    y1.append(10.1)

plt.plot(y1, label='pfpr_sock_freq_17')

plt.xlabel('Execution Time (ms/100)')
plt.ylabel('Frequency (GHz)')
ax.grid(which='both')
plt.xticks(np.arange(0, 1000, 100))
plt.yticks(np.arange(0, 24, 2))
plt.legend()
plt.savefig('exp8_pfpr_sock_freq_17.png', dpi=500)
plt.show()
