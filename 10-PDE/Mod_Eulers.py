# -*- coding: utf-8 -*-
"""
Created on Thu Oct  1 19:36:22 2020

@author: Admin
"""
import matplotlib.pyplot as plt;
import numpy as np
def fnval(x,y):
#    return y+x**2
    return (y**2-x**2)/(y**2+x**2)
h= float(input("Enter the step size "))
n=int(1/h)
x=np.zeros(n)
y=np.zeros(n)
ynew=np.zeros(n)
x[0]=0
y[0]=1
ynew[0]=1
for i in range(1,n):
    x[i]=h*i
    y[i]=y[i-1]+h*fnval(x[i-1],y[i-1])
    #WE obtain the first approximation of yi(0) from here

for i in range(1,n):
    temp1=0
    temp2=1
    if(abs(temp2-temp1)>0.001):
        temp1=y[i-1]+(h/2)*(fnval(x[i-1],y[i-1])+fnval(x[i],y[i])) #Trapezoidal
        temp2=y[i-1]+(h/2)*(fnval(x[i-1],y[i-1])+fnval(x[i],temp1))
        ynew[i]=temp2
    else:
        ynew[i]=temp2
       
print(ynew)       
plt.plot(x,y) 
plt.title('Modified Eulers method')  
plt.show()
