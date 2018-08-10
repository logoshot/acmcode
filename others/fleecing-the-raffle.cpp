#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
double f(int n,int p,int k)
{
         double ans=(double)k*p; 
         int i;
         for(i=0;i<p-1;++i)
         {
             ans/=(n+k-i),ans*=(n-i);
         }
         ans/=(n-i+k);
         return ans;
}
int main()
{
    int n,p;
    while(cin>>n>>p)
    {
         int k=n/(p-1);
         double ter=0;
         double ans=f(n,p,k);
         ter=max(ans,f(n,p,k+1));
         if(k>1) ter=max(ter,f(n,p,k-1));
         cout<<setprecision(9)<<ter<<endl;
    } 
    return 0;
}
