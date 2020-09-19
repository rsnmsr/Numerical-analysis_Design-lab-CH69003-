#include<bits/stdc++.h>
#define max 50
using namespace std;

// To find the actual value of the function at given point

double fx(vector<double> func,int order,double guess){
	double fnval=0;
	for(int i=0;i<order;i++){
		fnval+=pow(guess,order-i)*func[i];
	}
	return fnval+func[order];
}

//To differentiate the function and finding the value

double dfx(vector<double> func,int order,double guess){
	double fnval=0;
	for(int i=0;i<func.size();i++){
		func[i]=(order-i)*func[i];
	}
	func.resize(order);
	order--;
	for(int i=0;i<=order;i++){
		fnval+=pow(guess,order-i)*func[i];
	}
		
	return fnval;
	
}


//Finding root of polynomial-equation-newton-raphson code

double findroot(vector<double> gaussroot,double guess){
	bool nosoln=true;
    int order=gaussroot.size()-1;
while(nosoln){
	int order1=order;
	float tol=pow(10,-6);
	double fnvalue=fx(gaussroot,order1,guess);
	double dfnxval=dfx(gaussroot,order1,guess);
	double newx=guess-(fnvalue/dfnxval);
	if(abs(newx-guess)<tol){
//		cout<<guess<<endl;
		nosoln=false;
		return guess;
	}else{
		guess=newx;
	}
}

} 


int main(){
	int n,no_root=0;
	double guess;
	vector<double> myvector;
	cout<<"Enter the order of polynomial"<<endl;
	cin>>n;
	int total_term=n+1;
	myvector.resize(total_term);
	cout<<"Enter the coefficients of the polynomial"<<endl;
	for(int i=0;i<=n;i++){
		cin>>myvector[i];
	}
//Finding root of the polynomial by newton raphson
	cout<<"Enter an initial guess for the first root"<<endl;
	cin>>guess;
	
while(no_root<n){
    double root=findroot(myvector,guess);
    cout<<"The root obtained is "<< root<<endl;
    no_root++;

// After obtaining the root of the polynomial, Horners Method starts here
for(int i=1;i<n;i++){
	myvector[i]=root*myvector[i-1]+myvector[i];
}
myvector.resize(total_term-no_root);
guess=root;
}
//Just saw the final divided array

	return 0;
}
