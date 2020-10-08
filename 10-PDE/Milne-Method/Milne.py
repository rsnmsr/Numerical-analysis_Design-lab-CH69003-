# -*- coding: utf-8 -*-
"""
Created on Thu Oct  1 22:33:42 2020

@author: Admin
"""

import matplotlib.pyplot as plt;
import numpy as np
def fnval(x,y):
    return (y**2-x**2)/(y**2+x**2)
#    return 1+y**2
h= float(input("Enter the step size"))
n=int(1/h)
x=np.zeros(n)
y=np.zeros(n)
yp=np.zeros(n)
yc=np.zeros(n)

x[0]=0
y[0]=1


for i in range(1,n):
    x[i]=h*i
    k1=h*fnval(x[i-1],y[i-1])
    k2=h*fnval(x[i-1]+(h/2),y[i-1]+(k1/2))
    k3=h*fnval(x[i-1]+(h/2),y[i-1]+(k2/2))
    k4=h*fnval(x[i-1]+h,y[i-1]+k3)
    y[i]=y[i-1]+(k1+(2*k2)+(2*k3)+k4)/6
    

yp[0:4]=y[0:4]    
for i in range(3,n-1):
   yp[i+1]=y[i-3]+((2*fnval(x[i],y[i])-fnval(x[i-1],y[i-1])+2*fnval(x[i-2],y[i-2]))*(4*h/3))
  
yc[0:2]=y[0:2]
for i in range(1,n-1):
     yc[i+1]=y[i-1]+((4*fnval(x[i],y[i])+fnval(x[i-1],y[i-1])+fnval(x[i+1],y[i+1]))*(h/3))
    
#    print(i)
print(yp)
print(yc)
     
plt.plot(x,yp)
plt.title('Milne method')   
plt.show()
