#include<bits/stdc++.h>
using namespace std;
 
int main(){
float x[]={1,1.2,1.4,1.6,1.8,2,2.2};
float y[10][10]={0};
float val,p;
double dy=0,d2y=0;
int count=0; //Introduced count to decrease the redundent iterations

y[0][0]= 2.7183;y[1][0]=3.3201;y[2][0]=4.0552;y[3][0]=4.9530;y[4][0]=6.0496,y[5][0]=7.3891,y[6][0]=9.0250;


//Making a 2-d array and using such operation changes the complexity to n^2
for(int col=1;col<=7;col++){
	for(int row=0;row<6-count;row++){
		y[row][col]=y[row+1][col-1]-y[row][col-1];
	}
	count++;
}


for(int i=1;i<=5;i++){
	dy+=5*(pow(-1,i+1)*y[1][i])/i;
}

d2y=(y[0][2]-y[0][4]/12+y[0][5]/12)*25;

cout<<"The dy/dx and d2y/dx2 of function at 1.2 is "<<dy<<" and "<<d2y<<" respectively"<<endl; 


//If you want to see the fwd-diff matrix
//for(int i=0;i<7;i++){
//	for(int j=0;j<7;j++){
//		cout<<y[i][j]<<" ";
//	}
//	cout<<"\n";
//}

	return 0;
}
