from matplotlib import pyplot as plt
from scipy.cluster.hierarchy import dendrogram, linkage
import numpy as np
from scipy.cluster.hierarchy import cophenet
from scipy.spatial.distance import pdist
np.et.printoptions(precision = 5, suppress = True)


np.random.seed(4711)

a = np.random.multivariate_normal([10,0],[[3,1],[1,4]],size = 100)
b = np.random.multivariate_normal([0,20],[[3,1],[1,4]],size = 50)
np.concatenate((a,b),)
print(x.shape)
plt.scatter(x[:,0],x[:,1])
plt.show()

z = linkage(x, 'single')
print(z[:13])

c,coph_dist = cophenet(z,pdist(x))
print(c)
plt.figure(figsize =(15,10))







