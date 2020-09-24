#include<bits/stdc++.h>
using namespace std;

long double fnval(double x){
//	return exp(x)+1.5*x*x;
//  return 0.5*((x*x)+1)*(x+1);
//  return pow(x,3)-3*x;
	return 0.1*pow(x,6)-0.29*pow(x,5)+2.31*pow(x,4)-8.33*pow(x,3)+12.89*pow(x,2)-6.8*x+1;
//return 2*(x*x-4)*(x*x);
//return x*(x-1.5);
}

int main(){
	long double a=0,b=0,intrvl=0,x1=0,x2=0;
	int iter=0,max=15;
	cout<<"Input the initial, final value and interval range"<<endl;
	cin>>a>>b>>intrvl;
	double range=b-a;
	while((b-a)>0.1*range&&iter<max){
	
	
	x1=(b+a-intrvl)/2;
	x2=(b+a+intrvl)/2;
	
	long double val1=fnval(x1);
	long double val2=fnval(x2);
	
	cout<<iter+1<<" a: "<<a<<" b: "<<b<<" X1: "<<x1<<" X2: "<<x2<<" val1 "<<val1<<" val2 "<<val2<<endl;
	if(val1<val2){
		b=x2;
		a=a;
	}else{
		a=x1;
		b=b;
	}
	iter++;
}
cout<<"The possible min value is "<<(x1+x2)/2;
	return 0;
}
