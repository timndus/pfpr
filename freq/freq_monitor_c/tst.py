# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

x = []
y = []

with open('log/time_0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        x.append(int(row[0]))

with open('log/freq_0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y.append(int(row[0]))



plt.plot(x, y, 'go' ,label="core_0")

x = []
y = []

with open('log/time_1.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        x.append(int(row[0]))

with open('log/freq_1.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y.append(int(row[0]))

plt.plot(x, y, 'ro', label='core_1')

x = []
y = []

with open('log/time_2.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        x.append(int(row[0]))

with open('log/freq_2.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y.append(int(row[0]))

plt.plot(x, y, 'bo', label='core_2')

# Add a legend
plt.legend()

# Show the plot
plt.show()

