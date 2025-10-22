import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
n = 80
x = np.linspace(0,1,n)
y = np.linspace(0,1,n)
X,Y = np.meshgrid(x,y)
file = pd.read_csv(r"C:\Users\AJAY\Desktop\c++\lab3\data.csv")
jacobi = np.array(file['jacobi'])
gauss = np.array(file['gauss'])
sor = np.array(file['sor'])
gauss = gauss.reshape(n,n)
jacobi = jacobi.reshape(n,n)
sor = sor.reshape(n,n)
plt.figure(1,figsize=(5,5))
plt.contourf(x,y[::-1],gauss, cmap = 'jet')
plt.title('GAUSS')
plt.colorbar()
plt.figure(2,figsize=(5,5))
plt.contourf(x,y[::-1],sor, cmap = 'jet')
plt.title('SOR')
plt.colorbar()

plt.figure(3,figsize=(5,5))
plt.contourf(x,y[::-1],jacobi, cmap = 'jet')
plt.title('JACOBI')
plt.colorbar()

plt.show()
