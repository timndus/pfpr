# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv

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
y11 = []
y12 = []
y13 = []
y14 = []
y15 = []
y16 = []

with open('e_1200000_no.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y1.append(float(row[0]))

with open('e_2200000_no.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y7.append(float(row[0]))

with open('e_2500000_no.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y9.append(float(row[0]))

with open('e_3300000_no.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y14.append(float(row[0]))

with open('e_3501000_no.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y16.append(float(row[0]))


plt.plot(y1, '.', label='1.200 GHz')
plt.plot(y7, '+', label='2.200 GHz')
plt.plot(y9, 'o', label='2.500 GHz')
plt.plot(y14, '^', label='3.300 GHz')
plt.plot(y16, '*', label='3.501 GHz')

plt.xlabel('Sample number')
plt.ylabel('Power(W)')

## setting the limits on the x-axis and y-axis
plt.xlim(-1,20)
plt.ylim(0.6,1)

plt.title('')
plt.legend()
plt.show()
