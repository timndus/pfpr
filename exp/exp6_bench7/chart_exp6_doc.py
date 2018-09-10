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

with open('default_nemesis_max_scaling_17.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

with open('default_sock_max_scaling_17.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

#with open('pfpr_msg_on_nemesis_17_12.log','r') as csvfile:
#    plots = csv.reader(csvfile, delimiter='\n')
#    for row in plots:
#        if float(row[0]) > 77.4 and float(row[0]) < 77.5:
#            y3.append(float(row[0]))

with open('pfpr_msg_off_nemesis_17_12.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        if float(row[0]) > 77.4 and float(row[0]) < 77.5:
            y4.append(float(row[0]))

with open('pfpr_msg_off_sock_17_main.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        if float(row[0]) > 70.1 and float(row[0]) < 70.3:
            y5.append(float(row[0]))

plt.plot(y1, 'o', label='default_nemesis')
#plt.plot(y1, 'o')

plt.plot(y2, 'o', label='default_sock')
#plt.plot(y2, 'o')

#plt.plot(y3, label='pfpr_msg_on_nemesis')
#plt.plot(y3, 'o')

plt.plot(y4, '+', label='pfpr_nemesis')
#plt.plot(y4, '+')

plt.plot(y5, '^', label='pfpr_sock')
#plt.plot(y5, '^')

plt.xlabel('Sample Number')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
plt.xticks(np.arange(0, 20, 3))
plt.yticks(np.arange(65, 86, 5))
#plt.title('default_nemesis vs. default_sock vs. pfpr_nemesis_17_12 vs. pfpr_sock_17')
plt.legend(loc='lower right')
plt.savefig('no_title_default_nemesis_max_scaling_17_default_sock_max_scaling_17_vs_pfpr_nemesis_17_12_vs_pfpr_sock_17.png', dpi=500)
plt.show()
