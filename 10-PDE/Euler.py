import matplotlib.pyplot as plt;
import numpy as np
def fnval(x,y):
    return (y**2-x**2)/(y**2+x**2)
h= float(input("Enter the step size "))
n=int(1/h)
x=np.zeros(n)
y=np.zeros(n)
x[0]=0
y[0]=1
for i in range(1,n):
    x[i]=h*i
    y[i]=y[i-1]+h*fnval(x[i-1],y[i-1])

        
print(y)     
plt.plot(x,y)   
plt.title('Eulers method')
plt.show()     
    



