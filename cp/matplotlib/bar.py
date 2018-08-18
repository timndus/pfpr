import matplotlib.pyplot as plt

x = [2, 3, 5, 7, 8]
y = [4, 5, 2, 6, 4]

x2 = [1, 4, 6, 9]
y2 = [3, 5, 8, 3]


plt.bar(x, y, label='bar1', color='r')
plt.bar(x2, y2, label='bar2', color='c')

plt.legend()
plt.show()