import matplotlib.pyplot as plt

y = [2,4,9,4,93,58,2,9,720,59,48,593,58,2,5,94,5,438,3,4,54,3,539,3,83,539,35,833,493,83,893,593,583,85,9]

bins = [0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
plt.hist(y, bins, histtype='bar')

plt.legend()
plt.show()