#include<bits/stdc++.h>
using namespace std;

long double fnval(double x){
//	return exp(x)+1.5*x*x;
//  return 0.5*((x*x)+1)*(x+1);
//  return pow(x,3)-3*x;
//  return 2*(x*x-4)*(x*x);
	return 0.1*pow(x,6)-0.29*pow(x,5)+2.31*pow(x,4)-8.33*pow(x,3)+12.89*pow(x,2)-6.8*x+1;

//return x*(x-1.5);
}

int main(){
	long double a=0,b=0,mid=0,L=0,x1=0,x2=0;
	int iter=0,max=15;
	cout<<"Input the initial, final value "<<endl;
	cin>>a>>b;
	double range=b-a;
	while((b-a)>0.1*range&&iter<max){
	
	mid=(b+a)/2;
	L=b-a;
	x1=mid-(L/4);
	x2=mid+(L/4);
	
	long double val1=fnval(x1);
	long double valmid=fnval(mid);
	long double val2=fnval(x2);
	
	cout<<"a: "<<a<<"  b: "<<b<<endl;
	cout<<" X1: "<<x1<<" mid: "<<mid<<" X2: "<<x2<<" val1 "<<val1<<" ValMid "<<valmid<<" val2 "<<val2<<endl;
	if(valmid>val1&&valmid<val2){
		a=a;
		b=mid;
  }else if(valmid<val1&&valmid>val2){
  	a=mid;
  	b=b;
  }else{
  	a=x1;
  	b=x2;
  }
	iter++;
}
cout<<"The possible min value is "<<a<<" "<< b<<endl;
	return 0;
}
