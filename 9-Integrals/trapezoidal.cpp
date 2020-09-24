#include<bits/stdc++.h>
using namespace std;

double fnval(double x){
//	cout<<x<<" "<<((x*x)/pow(5*pow(x,4)+3*pow(x,2),(0.33333)))<<endl;
//	return ((x*x)/pow(5*pow(x,4)+3*pow(x,2),(0.33333)));
return exp((-5*pow(x,3))/2);
}
int main(){
	double a,b,step;
	int n;
	cout<<"Enter the initial,final points "<<endl;
	cin>>a>>b;
	cout<<"Enter number of subinterval "<<endl;
	cin>>n;
	step=(b-a)/n;
	double val1=(fnval(a)+fnval(b))/2;
	double sum=0;
	for(int i=1;i<n;i++){
		double x=a+(step*i);
		sum+=fnval(x);
}
double val2=(sum+val1)*step;
	cout<<val2;
	return 0;
}
