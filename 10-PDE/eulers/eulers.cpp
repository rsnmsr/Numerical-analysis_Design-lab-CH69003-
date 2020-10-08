//y"=(y^2-x^2)/(y^2+x^2)

#include<bits/stdc++.h>
using namespace std;

double fnval(double x,double y){
//	return (y*y-x*x)/(y*y+x*x);
return x*x+y;
}

int main(){
	vector <double>x;
	vector <double>y;
	int n;
	double h;
	cout<<"Enter interval size"<<endl;
	cin>>h;

	n=1/h; // For changing interval change it as (x2-x1)/h
	x.resize(n);
	y.resize(n);
	y[0]=1;x[0]=0;
	for(int i=1;i<=n-1;i++){
		x[i]=h*i;
		y[i]=y[i-1]+(h*(fnval(x[i-1],y[i-1])));
    	cout<<"Iteration "<<i<<"   "<<x[i]<<"   "<<y[i]<<endl;
	}

	return 0;
}

