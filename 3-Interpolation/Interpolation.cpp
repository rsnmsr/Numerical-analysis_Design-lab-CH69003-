//Newton forward  interpolation method to dtermine the value of tan x
//{x,y=(0.1,1003),(0.15,0.1511),(0.2,0.2027),(0.25,0.2553),(0.3,0.3039)}
#include<bits/stdc++.h>
using namespace std;
 

int main(){
float x[]={0.1,0.15,0.2,0.25,0.3};
float y[5][5]={0};
float val,p;

int count=0; //Introduced count to decrease the redundent iterations

y[0][0]=0.1003;y[1][0]=0.1511;y[2][0]=0.2027;y[3][0]=0.2553;y[4][0]=0.3039;
cout<<"Enter the point on which value is to be interpolated"<<endl;
cin>>val;
p=(val-x[0])/(x[1]-x[0]);

//Making a 2-d array and using such operation changes the complexity to n^2
for(int col=1;col<4;col++){
	for(int row=0;row<4-count;row++){
		y[row][col]=y[row+1][col-1]-y[row][col-1];
	}
	count++;
}

float result=y[0][0]+(p)*y[0][1]+(p*(p-1)/2)*y[0][2]+(p*(p-1)*(p-2)/6)*y[0][3]+(p*(p-1)*(p-2)*(p-3)/24)*y[0][3];
cout<<result;

//If you want to see the fwd-diff matrix
//for(int i=0;i<=4;i++){
//	for(int j=0;j<=4;j++){
//		cout<<y[i][j]<<" ";
//	}
//	cout<<"\n";
//}

	return 0;
}
