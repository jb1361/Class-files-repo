import numpy as np
import scipy as sp
from scipy import stats
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt


x = np.random.normal(0,1,size = 5000)
plt.hist(x,normed= True,bins = 50)
plt.xlabel('X values')
plt.ylabel('Y values')
plt.title('Normal Distribution Histogram')
plt.show()

W,P = sp.Stats.shapiro(x)
if p < 0.05: print('Reject: data is not normal')
else: print('Accept: Data is normal')

