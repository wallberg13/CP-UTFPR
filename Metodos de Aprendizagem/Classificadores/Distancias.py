#import numpy as np

"""
    Mesmas funcoes para fazer a mesma coisa, 
    Calcular uma distancia euclediana
"""

def emat(a, b):
    import math
    return np.sqrt(math.pow((a[0] - b[0]), 2) +
                   math.pow((a[1] - b[1]), 2) )
    
def sqrt_sum(a, b):
    return np.sqrt(np.sum((a - b)**2, axis=0))

def linalg_norm(a, b):
    return np.linalg.norm(a - b)

def edot(a, b):
    return np.sqrt(np.dot(a-b, a-b))

def scipy_distance(a, b):
    from scipy.spatial import distance
    return distance.euclidean(a, b)

def mhabis(a, b, std):
    return np.sqrt(np.sum( ((a - b)/std)**2 ))

def norma(X):
    from scipy import stats as st
    return st.zscore(X, axis=0)

#%%
"""
    Importando as base do iris.
"""

import numpy as np
from sklearn import datasets
iris = datasets.load_iris()
X = iris.data[:,:]
Y = iris.target

"""
    Calculando as classes, utilizando o unique para saber que classes sao
"""
classes = np.unique(Y)
cent = []

conv = np.cov(X.T)
conv_inv = np.linalg.inv(conv)

for clas in classes:
    cent.append(np.mean(X[np.where(Y == clas)], axis=0))


ponto = np.array([6.7, 3.1, 4.7, 0.48])

"""
    Classificacao
"""

prob = []
for clas in classes:
    prob.append(((ponto - cent[clas]).T) @ conv_inv @ (ponto - cent[clas]))

print(np.where(prob == np.min(prob)))

