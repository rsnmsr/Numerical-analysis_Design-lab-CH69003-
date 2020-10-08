# -*- coding: utf-8 -*-
"""
Created on Sun Oct  4 23:49:54 2020

@author: Admin
"""
#code for determining the integration of the function
'''
import sympy as sp
x=sp.Symbol('x')
y=sp.Symbol('y')
def funint(y):
    return (1+sp.integrate((y*y-x*x)/(y*y+x*x)))
#     return (1+sp.integrate(x+y*y))

y1=(funint(1))
y2=funint(y1)
print(y1)
print(y2)
'''


#calculate the integration value by 
'''
def Trapezoidal(f, a, b, n):
    h = (b-a)/float(n)
    s = 0.5*(f(a) + f(b))
    for i in range(1,n,1):
        s = s + f(a + i*h)
    return h*s

a = 0;  b = 1
n = 100
result = Trapezoidal(y1, a, b, n)
print(result)
'''
from scipy.integrate import quad
def integrand(x,y):
#    return -(x+(y*y))
     return -(y*y-x*x)/(y*y+x*x)
ans, err = quad(integrand,1.5707,0,1)
print(ans+1)