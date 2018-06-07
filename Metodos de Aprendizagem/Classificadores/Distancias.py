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

