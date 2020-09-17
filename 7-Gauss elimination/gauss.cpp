#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,temp;
    float a[10][10],c,d[10]={0};
    cout<<"Enter the total number of equations ";
    cin>>n;
    
    cout<<"Enter coefficients and the constants terms : \n";
    for(i=0;i<n;i++)
    {
        cout<<"Enter equation: "<<i+1<< "   ";
        for(j=0;j<=n;j++)
            cin>>a[i][j];
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
  cout<<"The values of the variable are as follows "<<endl;
    for(i=0;i<n;i++)
    cout<<d[i]<<endl;

    return 0;
}
