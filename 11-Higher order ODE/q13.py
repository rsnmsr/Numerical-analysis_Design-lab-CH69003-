from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt;
import numpy as np
def fnval(x,y,z):
    return x*y*z

def fnval1(x,y,z):
    return (x*y)/z

h= float(input("Enter the step size "))
n=int(2/h)
x=np.zeros(n)
y=np.zeros(n)
z=np.zeros(n)
x[0]=1
y[1]=0.3333  #y(1)=1/3=0.333
z[1]=1       #z(1)=1

#For the eqn 
#Equation will be solved for x=(1,2)
for i in range(1,n-1):
    x[i]=1+h*i
    # When calculating dy/dx=x*y*z, we keep the value of z constant, as it is independent 
    k1=h*fnval(x[i],y[i],z[i])      
    k2=h*fnval(x[i]+(h/2),y[i]+(k1/2),z[i])
    k3=h*fnval(x[i]+(h/2),y[i]+(k2/2),z[i])
    k4=h*fnval(x[i]+h,y[i]+k3,z[i])
    y[i+1]=y[i]+(k1+(2*k2)+(2*k3)+k4)/6
    
    # When calculating for dz/dx= x*y/z we keep y as constant
    k1=h*fnval1(x[i],y[i],z[i])
    k2=h*fnval1(x[i]+(h/2),y[i],z[i]+(k1/2))
    k3=h*fnval1(x[i]+(h/2),y[i],z[i]+(k2/2))
    k4=h*fnval1(x[i]+h,y[i],z[i]+k3)
    z[i+1]=z[i]+(k1+(2*k2)+(2*k3)+k4)/6
x=x[:len(x)-1]    
y=y[1:]
z=z[1:]
print("X Y and Z are:  ")
for i in range(len(x)):
    print(x[i]," ",y[i]," ",z[i])
fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot3D(x, y, z, 'red')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')