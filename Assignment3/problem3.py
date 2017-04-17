import matplotlib.pyplot as plt

from fft import fft
from fft import fft_power
from fft import ifft
from numpy import array
from numpy import real
import math
import time


# data downloaded from ftp://ftp.cmdl.noaa.gov/ccg/co2/trends/co2_mm_mlo.txt
print ' C02 Data from Mauna Loa'
data_file_name = 'co2_mm_mlo.txt'
file = open(data_file_name, 'r')
lines = file.readlines()
file.close()
print ' read', len(lines), 'lines from', data_file_name

window = False

yinput = []
xinput = []

for line in lines :
    if line[0] != '#' :
        try:
                words = line.split()
                xval = float(words[2])
                yval = float( words[4] )
                yinput.append( yval )
                xinput.append( xval )
        except ValueError :
                print 'bad data:',line

n=len(xinput)
s_x = 0
s_y = 0
s_xx = 0
s_xy = 0
sigma2 = 0
for i in range (0, n ): 
   s_x += xinput[i]
   s_y += yinput[i]
   s_xx += xinput[i]**2
   s_xy += xinput[i]*yinput[i]
denom = n * s_xx - s_x**2
if abs( denom ) < 0.000001 : 
      print 'Error! Denomominator is zero!'
      exit()


# Compute y-intercept and slope 
a = (s_xx * s_y - s_x * s_xy) / denom
b = (n*s_xy - s_x * s_y) / denom   

# Compute uncertainties
if n > 2 : 
      sigma = math.sqrt(sum((yinput[i] - (a+b*xinput[i]))**2 for i in range(n)) / (n-2))
      sigma_a = math.sqrt(sigma**2 * s_xx / denom)
      sigma_b = math.sqrt(sigma**2 * n / denom)
else :
      sigma = 0.
      sigma_a = 0.
      sigma_b = 0.

# Print out results
print ' Least squares fit of', n, 'data points'
print ' -----------------------------------'
print " slope   b = {0:6.2f} +- {1:6.2f} ".format( b, sigma_b)
print " Intercept with axis     a = {0:6.2f} +- {1:6.2f} ".format( a, sigma_a)
print ' Estimated v error bar sigma =', round(sigma, 1)

                


N = len(yinput)
log2N = math.log(N, 2)
if log2N - int(log2N) > 0.0 :
    print 'Padding with zeros!'
    pads = [300.0] * (pow(2, int(log2N)+1) - N)
    yinput = yinput + pads
    N = len(yinput)
    print 'Padded : '
    print len(yinput)
    # Apply a window to reduce ringing from the 2^n cutoff
    if window : 
        for iy in xrange(len(yinput)) :
            yinput[iy] = yinput[iy] * (0.5 - 0.5 * math.cos(2*math.pi*iy/float(N-1)))

y = array( yinput ) 
x = array([ float(i) for i in xrange(len(y)) ] )
Y = fft(y)



maxfreq = 10
# Now smooth the data
for iY in range(maxfreq, len(Y)-maxfreq ) :
    Y[iY] = complex(0,0)
    #Y[iY] = Y[iY] * (0.5 - 0.5 * math.cos(2*math.pi*iY/float(N-1))) 

    #for iY in range(0,N) : 
    #    Y[iY] = Y[iY] * math.exp(-1.0*iY / 50.0)

powery = fft_power(Y)
powerx = array([ float(i) for i in xrange(len(powery)) ] )

Yre = [math.sqrt(Y[i].real**2+Y[i].imag**2) for i in xrange(len(Y))]

ysmoothed = ifft(Y)
ysmoothedreal = real(ysmoothed)



ax1 = plt.subplot(2, 1, 1)
p1, = plt.plot( x, y )
p2, = plt.plot( x, ysmoothedreal )
ax1.legend( [p1,p2], ['Original', 'Smoothed'] )

ax2 = plt.subplot(2, 1, 2)
p3, = plt.plot( powerx, powery )
p4, = plt.plot( x, Yre )
ax2.legend( [p3, p4], ["Power", "Magnitude"] )
plt.yscale('log')


plt.show()
