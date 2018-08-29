# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []
y2 = []

with open('default_nemesis.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

with open('default_sock.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

plt.plot(y1, label='default_nemesis')
plt.plot(y1, 'o')

plt.plot(y2, label='default_sock')
plt.plot(y2, 'o')

plt.xlabel('x label')
plt.ylabel('ET')
plt.title('EXP6')
plt.legend()
plt.show()
