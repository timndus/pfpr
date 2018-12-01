import matplotlib.pyplot as plt
import numpy as np

# Random test data
np.random.seed(19680801)
datam = [
 [18.860655480,18.859292358,18.859342570,18.861049006,18.859197192,18.860480952,18.858749209,18.858517419,18.859003871,18.860286330,18.860993839,18.860344575]
 ,[18.866223294,18.865960739,18.869443738,18.871226040,18.867994675,18.874220161,18.869053320,18.869126255,18.869307592,18.866687138,18.869510957,18.870468155]
 ,[18.346120555,18.30203593,18.340633173,18.339264608,18.29424028,18.367334351,18.31863945,18.342279096,18.368334660,18.31137070,18.346325959,18.341370829]
 ,[17.242216269,16.778145144,17.386944428,17.290061745,16.778257901,17.589001347,17.241997586,16.778490678,17.389633922,17.290976585,16.777823237,17.589945622]
]

labels = ['default_nemesis', 'default_sock', 'pfpr_nemesis', 'pfpr_sock']

fig, axes = plt.subplots(nrows=1, ncols=1, figsize=(9, 4))

# rectangular box plot
bplot1 = axes.boxplot(datam,
                         vert=True,  # vertical box alignment
                         patch_artist=True,  # fill with color
                         labels=labels)  # will be used to label x-ticks
#axes.set_title('Rectangular box plot')

# fill with colors
colors = ['pink', 'lightblue', 'lightgreen', 'lightgreen']
for patch, color in zip(bplot1['boxes'], colors):
   patch.set_facecolor(color)

# adding horizontal grid lines
axes.yaxis.grid(True)
axes.set_xlabel('Algorithm')
axes.set_ylabel('Execution Time (sec)')

plt.savefig('box_plot_all_1.png', dpi=500)
plt.show()