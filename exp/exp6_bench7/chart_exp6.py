# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

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

with open('pfpr_msg_on_nemesis_17_12.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y3.append(float(row[0]))

with open('pfpr_msg_off_nemesis_17_12.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y4.append(float(row[0]))

with open('pfpr_msg_off_sock_17_main.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y5.append(float(row[0]))

plt.plot(y1, label='default_nemesis')
plt.plot(y1, 'o')

plt.plot(y2, label='default_sock')
plt.plot(y2, 'o')

plt.plot(y3, label='pfpr_msg_on_nemesis')
plt.plot(y3, 'o')

plt.plot(y4, label='pfpr_msg_off_nemesis')
plt.plot(y4, 'o')

plt.plot(y5, label='pfpr_msg_off_sock_17')
plt.plot(y5, 'o')

plt.xlabel('x label')
plt.ylabel('ET')
plt.title('EXP6')
plt.legend()
plt.show()
