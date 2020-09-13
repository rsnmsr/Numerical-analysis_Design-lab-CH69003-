#include<bits/stdc++.h>
using namespace std;

//f(x)=xe^x-cosx
//Function declaration to calculate the value of the fn, fx;

double func (double num){
	return exp(num)*num-cos(num);
}

double d_func (double num){
	return (num+1)*exp(num)+sin(num);
}

int main(){
	double x,fx,dfx,newx;
	bool nosoln=true;
	float tol=pow(10,-5);
	cout<<"Enter the initial guess value for the root of the equation"<<endl;
	cin>>x;
	while(nosoln){
		fx=func(x);
		dfx=d_func(x);
		newx=x-(fx/dfx);
		if(abs(newx-x)<tol){
			cout<<x<<endl;
			nosoln=false;
		}else{
			x=newx;
		}
		
		
	}
	return 0;
}
