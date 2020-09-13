#include<bits/stdc++.h>
using namespace std;

//f(x)=x^3-x-1
//Function declaration to calculate the value of the fn, fx;

double func (double num){
	return pow(num,3)-num-1;
}

double d_func (double num){
	return pow(num,2)*3-1;
}

int main(){
	double x,fx,dfx,newx;
	bool nosoln=true;
	float tol=pow(10,-6);
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
