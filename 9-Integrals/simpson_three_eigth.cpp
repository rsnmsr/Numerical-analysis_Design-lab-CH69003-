#include<bits/stdc++.h>
using namespace std;

double fnval(double x){
	
//	return ((x*x)/pow(5*pow(x,4)+3*pow(x,2),(0.33333)));
return exp((-5*pow(x,3))/2);
//	return pow((1-x*x),0.5);
//return (1/(1+x));
}

int main(){
	double a,b,step,sum1=0,sum2=0;
	int n;
	cout<<"Enter the initial,final points "<<endl;
	cin>>a>>b;
	cout<<"Enter number of subinterval "<<endl;
	cin>>n;
	step=(b-a)/n;
	double val1=(fnval(a)+fnval(b));
	for(int i=1;i<n;i++){
		 double x=a+(step*i);
		if(i%3==0){
			sum1+=2*fnval(x);
		}else{
			sum2+=3*fnval(x);
		}
	}
	double val2=(sum2+sum1+val1)*(3*step/8);
	cout<<val2;
	return 0;
}
