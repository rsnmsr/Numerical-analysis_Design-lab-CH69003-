//Successive substitution method
#include<bits/stdc++.h>
using namespace std;

//fn is x^3-x-1 or x=(1+x)^1/3
// 2 value will be entered with oposite sign to make the process faster and avoid divergene

//function to find recursive values of x
double func (double num){
	double y=exp(num);
	return cos(num)/y;
}


int main(){
	double a,b,x,fn;
	double tol=pow(10,-5);
	bool nosoln=true;

	cout<<"Enter two number a and b such that function value is opposite at both points"<<endl;
	cin>>a>>b;

	
	x=(a+b)/2;
	fn=func(x);
	while(nosoln){
		fn=func(x);
		if(abs(x-fn)<tol){
			cout<<x<<endl;
			nosoln=false;
		}else{
			x=fn;
		}
	}


	return 0;
}
