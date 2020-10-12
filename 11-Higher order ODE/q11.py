import matplotlib.pyplot as plt;
import numpy as np
def fnval(x,y):
    return -y

def fnval1(x,y):
    return y
#    return 1+y**2
h= float(input("Enter the step size "))
n=int(1/h)
x=np.zeros(n)
y=np.zeros(n)
y1=np.zeros(n)
x[0]=0
y[0]=0
y1[0]=1
#For the eqn dy2/dx=-y1, then simultaneously for dy1/dx=y2
for i in range(1,n):
    x[i]=h*i
    k1=h*fnval(x[i-1],y1[i-1])
    k2=h*fnval(x[i-1]+(h/2),y1[i-1]+(k1/2))
    k3=h*fnval(x[i-1]+(h/2),y1[i-1]+(k2/2))
    k4=h*fnval(x[i-1]+h,y1[i-1]+k3)
    y[i]=y[i-1]+(k1+(2*k2)+(2*k3)+k4)/6
    k1=h*fnval1(x[i-1],y[i-1])
    k2=h*fnval1(x[i-1]+(h/2),y[i-1]+(k1/2))
    k3=h*fnval1(x[i-1]+(h/2),y[i-1]+(k2/2))
    k4=h*fnval1(x[i-1]+h,y[i-1]+k3)
    y1[i]=y1[i-1]+(k1+(2*k2)+(2*k3)+k4)/6    
    
#print(y)
print(y1)
plt.plot(x,y1,x,np.cos(x))
plt.legend(['Numerical Solution','Analytical Solution'])
plt.xlabel('x')
plt.ylabel('y')
plt.show()