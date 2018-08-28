# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

y1 = []

with open('et_all.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y1.append(float(row[0]))

plt.plot(y1, label='et_change_with_freq_change')
plt.plot(y1, 'o')

plt.xlabel('x label')
plt.ylabel('ET')
plt.title('EXP5')
plt.legend()
plt.show()
