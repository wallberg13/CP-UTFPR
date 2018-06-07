# Open dataset from sklearn
from sklearn import datasets
import numpy as np

"""
    Qual a caracteristica mais discriminativa?
    Taxa de acerto para cada caracteristica?
        0 : 0.53 
        1 : 0.51
        2 : 0.78
        3 : 0.98
            
    Taxa de acerto para cada 2 caracteristicas? --- Sem z-core
        0,1 : 0.67
        0,2 : 0.87
        0,3 : 0.82
        1,2 : 0.80
        1,3 : 0.89
        2,3 : 0.93 
        
    Taxa de acerto para cada 3 caracteristicas?
        0,1,2: 0.80
        0,1,3: 0.93
        1,2,3: 0.93
        2,3,0: 0.76
        
    Taxa de acerto para cada 4 caracteristicas?
        0.91
        
    Taxa sem z-score?
        100% com 10 interacoes, 30% para teste, etha0=0.001
    
    Repetir experimento 10x. Imprimir media e desvio padrão.
    Plots!! 
    Qual dataset?

    Codigo para uma caracteristica
"""
iris = datasets.load_iris()
X = iris.data[:,:]
y = iris.target
#%%
print('Class labels:', np.unique(y))



# Splitting data into 70% training and 30% test data:
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1, stratify=y)

print('Labels counts in y:', np.bincount(y))
print('Labels counts in y_train:', np.bincount(y_train))
print('Labels counts in y_test:', np.bincount(y_test))


# Standardizing the features:
from sklearn.preprocessing import StandardScaler

sc = StandardScaler()
sc.fit(X_train)
X_train_std = sc.transform(X_train)
X_test_std = sc.transform(X_test)



# Training a perceptron via scikit-learn
from sklearn.linear_model import Perceptron
from sklearn.metrics import accuracy_score

x_std = []
x = []
for _ in range(100):
    # Classify test samples
    ppn = Perceptron(max_iter=2000, eta0=0.001, random_state=np.random, n_jobs=-1)
    ppn.fit(X_train_std, y_train)
    y_pred = ppn.predict(X_test_std)
    
    
    # Treinando sem normalizar
    ppn_z_out = Perceptron(max_iter=1000, eta0=0.001, random_state=np.random)
    ppn_z_out.fit(X_train, y_train)
    y_pred_z_out = ppn_z_out.predict(X_test)
    
    x_std.append(ppn.score(X_test_std, y_test))
    x.append(ppn.score(X_test, y_test))
    
np.array(x_std)
np.array(x)

print('Normalizado Media: ')

# Measuring the accuracy in 3 different ways
print('\nClassificador normalizado')
print('Misclassified samples: %d' % (y_test != y_pred).sum())
print('Accuracy: %.2f' % accuracy_score(y_test, y_pred))
print('Accuracy: %.2f' % ppn.score(X_test_std, y_test))

print('\nClassificador sem z-score')
print('Misclassified samples: %d' % (y_test != y_pred_z_out).sum())
print('Accuracy: %.2f' % accuracy_score(y_test, y_pred_z_out))
print('Accuracy: %.2f' % ppn_z_out.score(X_test, y_test))



#%%

# Plot_decision_region:
from matplotlib.colors import ListedColormap
import matplotlib.pyplot as plt

def plot_decision_regions(X, y, classifier, test_idx=None, resolution=0.02):

    # setup marker generator and color map
    markers = ('s', 'x', 'o', '^', 'v')
    colors = ('red', 'blue', 'lightgreen', 'gray', 'cyan')
    cmap = ListedColormap(colors[:len(np.unique(y))])

    # plot the decision surface
    x1_min, x1_max = X[:, 0].min() - 1, X[:, 0].max() + 1
    x2_min, x2_max = X[:, 1].min() - 1, X[:, 1].max() + 1
    xx1, xx2 = np.meshgrid(np.arange(x1_min, x1_max, resolution),
                           np.arange(x2_min, x2_max, resolution))
    Z = classifier.predict(np.array([xx1.ravel(), xx2.ravel()]).T)
    Z = Z.reshape(xx1.shape)
    plt.contourf(xx1, xx2, Z, alpha=0.3, cmap=cmap)
    plt.xlim(xx1.min(), xx1.max())
    plt.ylim(xx2.min(), xx2.max())

    for idx, cl in enumerate(np.unique(y)):
        plt.scatter(x=X[y == cl, 0], 
                    y=X[y == cl, 1],
                    alpha=0.8, 
                    c=colors[idx],
                    marker=markers[idx], 
                    label=cl, 
                    edgecolor='black')

    # highlight test samples
    if test_idx:
        # plot all samples
        X_test, y_test = X[test_idx, :], y[test_idx]

        plt.scatter(X_test[:, 0],
                    X_test[:, 1],
                    c='',
                    edgecolor='black',
                    alpha=1.0,
                    linewidth=1,
                    marker='o',
                    s=100, 
                    label='test set')


# Training a perceptron model using the standardized training data:
X_combined_std = np.vstack((X_train_std, X_test_std))
y_combined = np.hstack((y_train, y_test))

plot_decision_regions(X=X_combined_std, y=y_combined,
                      classifier=ppn, test_idx=range(105, 150))
plt.xlabel('petal length [standardized]')
plt.ylabel('petal width [standardized]')
plt.legend(loc='upper left')

plt.tight_layout()
#plt.savefig('images/03_01.png', dpi=300)
plt.show()