import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
import math
algorithm1 = []
algorithm2 = []
bettertime = []
i = 1
alg1 = 0
alg2 = 0
while i < 20:
	alg1 = 100*(i**2)
	alg2 = 2**i
	if(alg1 < alg2):
		bettertime.append((i-1))
	algorithm1.append(alg1)
	algorithm2.append(alg2)

	i = i + 1
	
print(algorithm1)
print(algorithm2)	
print(bettertime)
plt.plot(algorithm1,color = 'green', label = '100n^2')
plt.plot(algorithm2,color = 'blue', label = '2^n')
plt.legend()
plt.show()


'''
import numpy as np
import matplotlib.pyplot as plt

X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
C, S = np.cos(X), np.sin(X)

plt.plot(X, C)
plt.plot(X, S)

plt.show()


fig, ax = plt.subplots()
	ax.plot(actual_values,'o',markersize = 1, color = 'green', label = 'Actual Price')
	ax.plot(predictions,'o',markersize = 1, color = 'blue', label = 'Predicted Price')
	plt.legend()
	fig2, ax2 = plt.subplots()
	ax2.plot(cost_history,'o',markersize = 1, color = 'blue')
	plt.show()
'''