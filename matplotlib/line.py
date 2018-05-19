import matplotlib.pyplot as plt

x = [4, 5, 6]
y = [9, 4, 7]

x2 = [3,4,8]
y2 = [4,6,2]

plt.plot(x, y, label='First line')
plt.plot(x2, y2, label='Second line')
plt.xlabel('x label')
plt.ylabel('y label')
plt.title('title')
plt.legend()
plt.show()
