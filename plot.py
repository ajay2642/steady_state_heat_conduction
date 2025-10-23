import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
n = 80
x = np.linspace(0,1,n)
y = np.linspace(0,1,n)
file = pd.read_csv(r"C:\Users\AJAY\Desktop\c++\lab3\data.csv") 
jacobi = np.array(file['jacobi'])
gauss = np.array(file['gauss'])
sor = np.array(file['sor'])
gauss = gauss.reshape(n,n)
jacobi = jacobi.reshape(n,n)
sor = sor.reshape(n,n)
fig, axes = plt.subplots(1, 3, figsize=(12, 4), constrained_layout=True)

c1 = axes[0].contourf(x, y[::-1], gauss, cmap='jet')
axes[0].set_title('GAUSS')
axes[0].set_aspect('equal')
fig.colorbar(c1, ax=axes[0], shrink=0.7)

c2 = axes[1].contourf(x, y[::-1], sor, cmap='jet')
axes[1].set_title('SOR')
axes[1].set_aspect('equal')
fig.colorbar(c2, ax=axes[1], shrink=0.7)

c3 = axes[2].contourf(x, y[::-1], jacobi, cmap='jet')
axes[2].set_title('JACOBI')
axes[2].set_aspect('equal')
fig.colorbar(c3, ax=axes[2], shrink=0.7)
plt.show()


