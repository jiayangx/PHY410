import matplotlib.pyplot as plt

from fft import fft
from numpy import array
import math



#  For x-axes uses words[0], y-axes uses word[1], z-axes uses word[2]
data_file_name = 'LorenzRK4A_plot.txt'
file = open(data_file_name, 'r')
lines = file.readlines()
file.close()
print ' read', len(lines), 'lines from', data_file_name

yinput = []
xinput = []

for line in lines :
    if line[0] != '#' :
        try:
            words = line.split()
            xval = float(len(yinput)*0.05)
            yval = float( words[0] )
            yinput.append( yval )
            xinput.append( xval )
        except ValueError :
            print 'bad data:',line

y = array( yinput[0:4096] ) 
x = array([ float(i) for i in xrange(len(y)) ] )
Y = fft(y)

Yre = [math.sqrt(Y[i].real**2+Y[i].imag**2) for i in xrange(len(Y))]


plt.subplot(2, 1, 1)
plt.plot( x, y )

plt.subplot(2, 1, 2)
plt.plot( x, Yre )
plt.yscale('log')


plt.show()
