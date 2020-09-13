#include<bits/stdc++.h>
using namespace std;

//f(x)=x*e^x-cos(x)
//Function declaration to calculate the value of the fn, fx;

double func (double num){
	return exp(num)*num-cos(num);
}

int main(){

	double a,b,c,fa,fb,fc,answer;
	double error=0.00001;
	bool nosolution=true;
	
	cout<<"Enter the initial guess values a and b"<<endl;
	cin>>a>>b;

	while(nosolution){
	fa=func(a);	
	fb=func(b);
	
	//Check if the initial assumption is the root
	if(fa==0){
		cout<<"The root is"<<a<<endl;
	}
	if(fb==0){
		cout<<"The root is"<<a<<endl;
	}
	
	if(fa*fb<0){
		c=(a*fb-b*fa)/(fb-fa);
	    fc=func(c);
	
	if(abs(fc)>error){
		if(fa*fc>0){
			a=c;
			b=b;
		}else{
			a=a;
			b=c;
		}
		
	}else if(abs(fc)<=error){
		cout<<c;
		nosolution=false;
	
	}
		
	}else{
		cout<<"Improper selection of range ! Try once again"<<endl;
		break;
	}

	} 
	
	return 0;
}
