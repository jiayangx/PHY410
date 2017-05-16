import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from read_plot_3d import read_plot_3d

x,y,z = read_plot_3d( 'LorenzRK4A_plot.txt' )

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

#ax.scatter(x, y, z)
plt.plot(x,y,z)
plt.show()

