import matplotlib.pyplot as plt
import numpy as np
import csv

x = []

with open('log/time.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        x.append(float(row[0]))

y = []

with open('log/time.logenergy_uj.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y.append(float(row[0]))

plt.plot(x, y)


plt.legend()
plt.show()

