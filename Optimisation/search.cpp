#include<bits/stdc++.h>
using namespace std;
double fnval(double x){
//	return exp(x)+1.5*x*x;
//  return 0.5*((x*x)+1)*(x+1);
//  return pow(x,3)-3*x;
//return 2*(x*x-4)*(x*x);
	return 0.1*pow(x,6)-0.29*pow(x,5)+2.31*pow(x,4)-8.33*pow(x,3)+12.89*pow(x,2)-6.8*x+1;
//return x*(x-1.5);
}
int main(){
	double step,point1;
	int maxiter=15;
	int count=0;
	cout<<"Enter the starting point and the step size "<<endl;
	cin>>point1>>step;
		double i_val1=fnval(point1+step*pow(2,0));
		double i_val2=fnval(point1+step*pow(2,1));
		
		for(int i=1;i<=maxiter;i++){
		
        double val1=fnval(point1+step*pow(2,i));
		double val2=fnval(point1+step*pow(2,i+1));
//		cout<<val1<<" "<<val2<<endl;
		double del1=val1-i_val1;
		double del2=val2-i_val2;
//		cout<<del1<<" "<<del2<<endl;
        cout<<i <<" Value "<<val1<<" point:"<<point1+step*pow(2,i) <<endl;  
		if(val1*val2<0){
//			cout<<" Root exist between points" <<point1+step*pow(2,i)<<" and "<<point1+step*pow(2,i+1)<<" and values at this point are "<<val1<<" "<<val2<<endl;
//			break;
		}else{
			i_val1=val1;
			i_val2=val2;
		}
		}
		
	
	return 0;
}
