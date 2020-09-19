#include<bits/stdc++.h>
using namespace std;

void gauss(double a1[],double a2[]){
int n=3;
double a[10][10],d[10]={0},c;
int i,j,k;
int count=0;
//Just mixing the input array as single array for gauss jordan method
	    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=a1[j+count];
    }
    a[i][n]=a2[i];
    count++;
}

for(i=n-1;i>0;i--)        // partial pivoting
    {
        if(a[i-1][0]<a[i][0])
            for(j=0;j<=n;j++)
            {
                c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }
    // Forward elimination process
    for(k=0;k<n-1;k++)
        for(i=k;i<n-1;i++)
        {
            c= (a[i+1][k]/a[k][k]) ;
            
            for(j=0;j<=n;j++)
                a[i+1][j]-=c*a[k][j];
        }




    //Backward Substitution method

    for(i=n-1;i>=0;i--)
    {
        c=0;
        for(j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];
            
        d[i]=(a[i][n]-c)/a[i][i];
    }
  cout<<"The values of the index a,b,c are as follows "<<endl;
    for(i=0;i<n;i++)
    cout<<d[i]<<endl;	
	
	
}


//Main function derives the term for the matrix to be solved
int main(){
//	double x[]={1,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8};
//	double y[]={1.175,1.336,1.51,1.698,1.904,2.129,2.376,2.646,2.942};
    double x[]={1,3,4,6};
	double y[]={0.63,2.05,4.08,10.78};
	int a_len=sizeof(x)/sizeof(x[0]);
	double sx=0,sy=0,sx2=0,sx3=0,sx4=0,sxy=0,sx2y=0;
	for(int i=0;i<a_len;i++){
		sx+=x[i];
		sy+=y[i];
		sx2+=x[i]*x[i];
		sx3+=pow(x[i],3);
		sx4+=pow(x[i],4);
		sxy+=x[i]*y[i];
		sx2y+=pow(x[i],2)*y[i];
		
	}
	
   double arr1[]={a_len,sx,sx2,sx3,sx4};
   double arr2[]={sy,sxy,sx2y};
    gauss(arr1,arr2);
//	cout<<sx<<" "<<sy<<" "<<sx2<<" "<<sx3<<" "<<sx4<<" "<<sxy<<" "<<sx2y;
	
	return 0;
}
