import numpy as np
from matplotlib import pyplot as plt
import random as rd

peso = [65.8, 33, 99.7, 115.2]
altura = [1.88, 1.71, 1.99, 1.85]

#for i in range(len(peso)):
#    plt.scatter(peso[i], altura[i],s=200, color=(rd.random(), rd.random(), rd.random()))

cores=['green','blue','orange','red']
#plt.scatter(peso, altura, s=200, color=cores, marker='o')
plt.plot(peso, altura)

plt.xlabel('peso')
plt.ylabel('altura')
plt.title('numeros inventados pelo Pablo')
plt.ylim(0, 2.2)

#%%
import numpy as np
from matplotlib import pyplot as plt

arq = open('city_temp.txt','r')
linhas = arq.readlines()

temperaturas = []
latitudes = []
longitudes = []

for i in range(1, len(linhas)):
    L = linhas[i]
    L = L.replace('\r\n', '')
    cidade, tem, lati, longi = L.split('\t')
    temperaturas.append(float(tem))
    latitudes.append(float(lati))
    longitudes.append(float(longi)*(-1)) # Inverter as longitudes

#plt.scatter(latitudes, temperaturas)
#plt.xlabel('Latitude')
#plt.ylabel('Temp (F)')

#plt.figure()
#plt.scatter(longitudes, latitudes, s=100, c=np.array(temperaturas)/80, cmap='jet')

plt.figure()
plt.hist(temperaturas, 20)
#%% 

for i in range(10000):
    print("Este i é: ",i,".",end="\r")