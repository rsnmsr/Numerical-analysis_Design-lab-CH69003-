//Curve fitting in equation of form ae^x
#include<bits/stdc++.h>
using namespace std;
int main(){
	//Constant arrays have been choosen for this particular test
	double x[]={2,4,6,8,10};
	double y[]={4.077,11.084,30.128,81.897,222.62};

//	double x[]={1,3,5,7,9};
//	double y[]={2.473,6.722,18.274,49.673,135.026};
	//For determining the size of the array
	int arr_len=sizeof(x)/sizeof(x[0]);
	
	// The terms sx,sY are declared to do the summation at the time of calculation in single loop
	
	double sx=0,sY=0,sX2=0,sXY=0;

	double X2[arr_len];double Y[arr_len];double XY[arr_len];
	for(int i=0;i<arr_len;i++){
		X2[i]=x[i]*x[i];
		Y[i]=log(y[i]);
		XY[i]=x[i]*Y[i];
		sx+=x[i];
		sY+=Y[i];
		sX2+=X2[i];
		sXY+=XY[i];
	}
//	cout<<sx<<" "<<sY<<" "<<sXY<<" "<<sX2;	
	double avgx=sx/arr_len;
	double avgy=sY/arr_len;
	
	double b=((arr_len*sXY)-(sx*sY))/((arr_len*sX2)-(sx*sx));
	double a0=avgy-b*avgx;
	double a=exp(a0);
	
	
	cout<<"After curve fitting the values of a and b are "<<a<<" and "<<b;
	



	return 0;
}
