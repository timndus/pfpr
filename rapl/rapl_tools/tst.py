# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

x = []

with open('log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        x.append(float(row[0]))

plt.plot(x, label='log')



y = []

with open('log_stress','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y.append(float(row[0]))

plt.plot(y, label='log_stress')


plt.legend()
plt.show()

