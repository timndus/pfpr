# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

x = []
y = []

with open('time_0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        x.append(int(row[0]))

with open('freq_0.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y.append(int(row[0]))


# Prepare the data
#x = np.linspace(0, 10, 100)

# Plot the data
plt.plot(x, y, label='linear')

# Add a legend
plt.legend()

# Show the plot
plt.show()

