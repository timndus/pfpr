# Import the necessary packages and modules
import matplotlib.pyplot as plt
import numpy as np
import csv
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

#repet1, tepeat 2 repet 3 repeat 4
#nemesis
#sock
#pfpr_nemesis
#pfpr_sock
nemesis = [18.8, 37.7, 151 ,302, 602, 1202]
sock = [18.8, 37.7, 151, 302, 602, 1202]
pfpr_nemesis = [18.4, 36.5, 146, 292, 583, 1170]
pfpr_sock = [17.3, 34.5, 137, 275, 550, 1100]


plt.plot(nemesis)
plt.plot(sock)
plt.plot(pfpr_nemesis)
plt.plot(pfpr_sock)

plt.plot(nemesis, '*', label='default_nemesis')
plt.plot(sock, '^', label='default_sock')
plt.plot(pfpr_nemesis, 'o', label='pfpr_nemesis')
plt.plot(pfpr_sock, '+', label='pfpr_sock')

plt.xlabel('Repeat')
plt.ylabel('Execution Time (sec)')
ax.grid(which='both')
#plt.xticks(np.arange(-1, 6, 1))
#plt.yticks(np.arange(18.48, 18.49, 0.001))
plt.legend()
plt.savefig('overall.png', dpi=500)
plt.show()

