//L6/Lo=0.07692, hence for a 10% range we will use it
#include<bits/stdc++.h>
using namespace std;

long double fnval(double x){
//	return exp(x)+1.5*x*x;
//  return 0.5*((x*x)+1)*(x+1);
//  return pow(x,3)-3*x;
//  return 2*(x*x-4)*(x*x);
//	return 0.1*pow(x,6)-0.29*pow(x,5)+2.31*pow(x,4)-8.33*pow(x,3)+12.89*pow(x,2)-6.8*x+1;
  return 0.65-(0.75/(1+(x*x)))-0.65*x*atan(1/x);
//return x*(x-1.5);
}

int main(){
	long double a=0,b=0,mid=0,L=0,x1=0,x2=0,lim1;
	int iter=1,max=6;
	int count=1;
	cout<<"Input the initial, final value "<<endl;
	cin>>a>>b;
	double range=b-a;
    lim1=range*5/13;	
	x1=a+lim1;
	x2=b-lim1;
//	cout<<x1<<" "<<x2<<endl;
//	cout<<lim1<<endl;
	
	while(iter<=max){
		
		if(x1>x2){
			long double temp=x1;
			x1=x2;
			x2=temp;
		}

	long double val1=fnval(x1);
	long double val2=fnval(x2);
	cout<<"Iteration no:"<<count<<endl;
	cout<<"a: "<<a<<" b: "<<b<<" X1: "<<x1<<" X2: "<<x2<<" val1 "<<val1<<"  val2 "<<val2<<endl;

//	if(val1<val2){
//		b=x2;
//		x2=x1;
//		x1=b-x2;
//	}else{
//		a=x1;
//		b=x2;
//		x1=x2-x1;
//	}
	if(val1<val2){
		b=x2;
		x2=x1;
		x1=a+(b-x2);
	}else{
		a=x1;
//		b=x2;
		x1=a+(b-x2);
	}
	count++;
	iter++;
}
cout<<"The possible a,b "<<a<<" "<<b<<endl;
	return 0;
}
