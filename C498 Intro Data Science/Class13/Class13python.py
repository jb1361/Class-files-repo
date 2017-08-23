import matplotlib.pyplot as plt
from sklearn import decomposition
from sklearn import datasets
from mpl_toolkits.mplot3d import Axes3D
iris = datasets.load_iris()
x = iris.data
pca = decomposition.PCA(n_components = 3)
pca.fit(x)
x = pca.transform(x)
print(pca.explained_variance_ratio_)
#fig = plt.figure(1,figsize =(7,5))
#ax = fig.add_subplot(111,projection = '3d')
#ax.scatter(x[:,0],x[:,1],x[:,2])
#plt.show()
print('================================================================')

#=====================================================


from sklearn.cluster import AgglomerativeClustering
from sklearn import cluster,datasets

x_iris = iris.data
y_iris = iris.target
iris = AgglomerativeClustering(n_clusters = 3, linkage = 'ward').fit_predict(x_iris)
#linkage = 'complete'  | 'average'
#ward seems to give the best results
print('Prediction:\n',iris)
print('Actual:\n',y_iris)
print('================================================================')

#============================================
#Generate 3d data of 40 sample data points, normal distribution
#generate 2 classes of data
#sample means m1 = [0/0/0]  m2 = [1/1/1]  
#covariance matrix -> identitymatrix = [1/0/0,0/1/0,0/0/1]
#why 3d? pca allows dimension reduction 3d->2d
#generate 3 by 20 datasets 

import numpy as np
np.random.seed(7411)
mu_vec1 = np.array([0,0,0])
mu_vec2 = np.array([1,1,1])
cov_mat = np.array([[1,0,0],[0,1,0],[0,0,1]])
group1 = np.random.multivariate_normal(mu_vec1,cov_mat,20).T
group2 = np.random.multivariate_normal(mu_vec2,cov_mat,20).T

fig = plt.figure(figsize = (8,6))
ax = fig.add_subplot(111,projection = '3d')
plt.rcParams['legend.fontsize'] = 10
ax.plot(group1[0,:],group1[1,:],group1[2,:],'o',markersize = 8, color = 'blue', alpha = 0.5,label = 'group1')
ax.plot(group2[0,:],group2[1,:],group2[2,:],'o',markersize = 8, color = 'red', alpha = 0.5,label = 'group2')
plt.title('Data Samples for group1 and group2')
ax.legend(loc = 'upper right')
plt.show()


#merge group1 and group2 into 3x40 matrix
#compute mean vector of d-dimensions
#compute covariance matrix
#

all_samples = np.concatenate((group1,group2),axis = 1)

mean_x = np.mean(all_samples[0,:])
mean_y = np.mean(all_samples[1,:])
mean_z = np.mean(all_samples[2,:])

mean_vector = np.array([[mean_x],[mean_y],[mean_z]])

cov_mat = np.cov([all_samples[0,:],all_samples[1,:],all_samples[2,:]])
print('covariance matrix:\n', cov_mat)
print('================================================================')

eig_value, eig_vector = np.linalg.eig(cov_mat)
print('eigenvector:\n',eig_vector)
print('================================================================')
print('eigenvalues:\n',eig_value)
print('================================================================')
eig_pair = [(np.abs(eig_value[i]),eig_vector[:,i]) for i in range (len(eig_value))]
eig_pair.sort(key = lambda x: x[0], reverse = True)
matrix_w = np.hstack((eig_pair[0][1].reshape(3,1),eig_pair[1][1].reshape(3,1)))
print(matrix_w)
print('================================================================')
transform = matrix_w.T.dot(all_samples)
print(transform)
print('================================================================')

plt.plot(transform[0,0:20],transform[1,0:20],'o',markersize = 8,color = 'blue',alpha = 0.5,label = 'group1')
plt.plot(transform[0,20:40],transform[1,20:40],'^',markersize = 8,color = 'red',alpha = 0.5,label = 'group2')
plt.show()



