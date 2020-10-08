# -*- coding: utf-8 -*-
"""
Created on Thu Oct  1 21:35:27 2020

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
yab=np.zeros(n)
yam=np.zeros(n)

x[0]=0
y[0]=1


for i in range(1,n):
    x[i]=h*i
    k1=h*fnval(x[i-1],y[i-1])
    k2=h*fnval(x[i-1]+(h/2),y[i-1]+(k1/2))
    k3=h*fnval(x[i-1]+(h/2),y[i-1]+(k2/2))
    k4=h*fnval(x[i-1]+h,y[i-1]+k3)
    y[i]=y[i-1]+(k1+(2*k2)+(2*k3)+k4)/6
    
#differentloop will be used for adams-Bashforth and Adams-Moulton Methods
yab[0:4]=y[0:4]    
for i in range(3,n-1):
    #Adam-Bashforth Formula
    yab[i+1]=y[i]+((55*fnval(x[i],y[i])-59*fnval(x[i-1],y[i-1])+37*fnval(x[i-2],y[i-2])-9*fnval(x[i-3],y[i-3]))*(h/24))
    #Adams-Moulton Formula
yam[0:3]=y[0:3]
for i in range(2,n-1):
     yam[i+1]=y[i]+((9*fnval(x[i+1],yab[i+1])+19*fnval(x[i],y[i])-5*fnval(x[i-1],y[i-1])+fnval(x[i-2],y[i-2]))*(h/24))
    
#    print(i)
print(yab,yam)
     
plt.plot(x,yab)
plt.title('Adam-Bashforth Formula')   
plt.show()
plt.plot(x,yam)  
plt.title('Adam-Moulton Formula')   
plt.show()