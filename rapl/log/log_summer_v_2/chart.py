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

with open('16_100.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y1.append(float(row[0]))

with open('17_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y2.append(float(row[0]))

with open('18_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y3.append(float(row[0]))

with open('19_100.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y4.append(float(row[0]))

with open('21_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y5.append(float(row[0]))

with open('22_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y6.append(float(row[0]))

with open('23_100.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y7.append(float(row[0]))

with open('24_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y8.append(float(row[0]))

with open('25_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y9.append(float(row[0]))

with open('26_100.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y10.append(float(row[0]))

with open('27_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y11.append(float(row[0]))

with open('28_100.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y12.append(float(row[0]))

with open('30_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y13.append(float(row[0]))

with open('31_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y14.append(float(row[0]))

with open('32_100.log','r') as csvfile:
    plots = csv.reader(csvfile, delimiter='\n')
    for row in plots:
        y15.append(float(row[0]))

with open('33_100.log','r') as csvfile:
	plots = csv.reader(csvfile, delimiter='\n')
	for row in plots:
	    y16.append(float(row[0]))


plt.plot(y1, label='1600')
plt.plot(y2, label='1700')
plt.plot(y3, label='1800')
plt.plot(y4, label='1900')
plt.plot(y5, label='2100')
plt.plot(y6, label='2200')
plt.plot(y7, label='2300')
plt.plot(y8, label='2400')
plt.plot(y9, label='2500')
plt.plot(y10, label='2600')
plt.plot(y11, label='2700')
plt.plot(y12, label='2800')
plt.plot(y13, label='3000')
plt.plot(y14, label='3100')
plt.plot(y15, label='3200')
plt.plot(y16, label='3300')

plt.xlabel('Sample number')
plt.ylabel('Power(W)')

## setting the limits on the x-axis and y-axis
#plt.xlim(1,20)
#plt.ylim(0.6,1)

plt.title('')
plt.legend()
#plt.savefig('foo.png', dpi=1500)
plt.show()
