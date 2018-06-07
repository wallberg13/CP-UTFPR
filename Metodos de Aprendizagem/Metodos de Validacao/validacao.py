#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 24 19:08:13 2018

@author: sir-berg
"""

import numpy as np
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import StratifiedKFold
from sklearn.model_selection import LeaveOneOut
from sklearn import metrics

iris = datasets.load_iris()
X = iris.data[:,:]
Y = iris.target

#%%
"""
    Definindo um objeto do tipo KFold estratificado com 10 dividoes
"""
k = 10
test = StratifiedKFold(n_splits=k)
knn = KNeighborsClassifier(n_neighbors=3, n_jobs=-1)
mean_kfold = []
mtx_confusion = []
for train_id, test_id in test.split(X, Y):
    X_treino, X_teste = X[train_id], X[test_id]
    Y_treino, Y_teste = Y[train_id], Y[test_id]
    
    knn.fit(X_treino, Y_treino)
    res_test = knn.predict(X_teste)
    mtx_confusion.append(metrics.confusion_matrix(Y_teste, res_test))
    print("Result_Teste:     " , res_test)
    print("Teste_Verdadeiro: " , Y_teste)
    mean_kfold.append(metrics.accuracy_score(Y_teste, res_test))
    print("Acertos: ", metrics.accuracy_score(Y_teste, res_test), "\n")
    
print(k,"-Folds ---> Taxa de Acertos media: ", np.mean(mean_kfold))
print("Matriz de Confusão: ")
print(np.sum(mtx_confusion,axis=0))

#%%
"""
    Para Leave-one-out
"""
test = LeaveOneOut()
knn = KNeighborsClassifier(n_neighbors=3, n_jobs=-1)
mean_kfold = []
pred = []
for train_id, test_id in test.split(X):
    X_treino, X_teste = X[train_id], X[test_id]
    Y_treino, Y_teste = Y[train_id], Y[test_id]

    knn.fit(X_treino, Y_treino)
    res_test = knn.predict(X_teste)
    pred.append(res_test)
    
    mean_kfold.append(metrics.accuracy_score(Y_teste, res_test))

print("Leave-One-Out ---> Taxa de Acertos media: ", np.mean(mean_kfold))
metrics.confusion_matrix(Y, pred)