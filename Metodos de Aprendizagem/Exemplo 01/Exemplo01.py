"""
Spyder Editor

This is a temporary script file.
"""
from sklearn import datasets
import numpy as np
import pandas as pd

iris = datasets.load_iris()
X = iris.data[:,[2, 3]]
y = iris.target

print('Class Labels: ', np.unique(y))

from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1, stratify=y)

from sklearn.preprocessing import StandardScaler

sc = StandardScaler()
sc.fit(X_train)
X_train_std = sc.transform(X_train)
X_test_std = sc.transform(X_train)

"""
    Tutorial do aprendizagem de maquina.
    
    1 - Pegar a base de dados
    2 - Dividir em teste e treinamento a base (split)
    3 - Normalizar as bases (funcao fit no treinamento e aplicar nas bases)
    4 - Escolher um classificador e treinas
    5 - Usar os modelos treinados para classificar
    6 - Verificar a taxa de acerto
    7 - Se quiser, fazer o plot
    
"""