# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

y1 = []
y2 = []
y3 = []
y4 = []
y5 = []
y6 = []
y7 = []
y8 = []
y9 = []
y10 = []

with open('nemesis/default_nemesis_repeat_1.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

with open('nemesis/default_nemesis_repeat_4.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

with open('nemesis/default_nemesis_repeat_8.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y3.append(float(row[0]))

with open('nemesis/default_nemesis_repeat_16.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y4.append(float(row[0]))

with open('nemesis/default_nemesis_repeat_32.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y5.append(float(row[0]))


with open('sock/default_sock_repeat_1.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y6.append(float(row[0]))

with open('sock/default_sock_repeat_4.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y7.append(float(row[0]))

with open('sock/default_sock_repeat_8.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y8.append(float(row[0]))

with open('sock/default_sock_repeat_16.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y9.append(float(row[0]))

with open('sock/default_sock_repeat_32.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y10.append(float(row[0]))


plt.plot(y1, label='default_nemesis_repeat_1')
plt.plot(y2, label='default_nemesis_repeat_4')
plt.plot(y3, label='default_nemesis_repeat_8')
plt.plot(y4, label='default_nemesis_repeat_16')
plt.plot(y5, label='default_nemesis_repeat_32')

plt.plot(y6, label='default_sock_repeat_1')
plt.plot(y7, label='default_sock_repeat_4')
plt.plot(y8, label='default_sock_repeat_8')
plt.plot(y9, label='default_sock_repeat_16')
plt.plot(y10, label='default_sock_repeat_32')


plt.xlabel('Sample Number')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
#plt.xticks(np.arange(0, 20, 3))
#plt.yticks(np.arange(65, 86, 5))
plt.legend()
#plt.savefig('exp8_pfpr_sock_17_execution_time.png', dpi=500)
plt.show()
