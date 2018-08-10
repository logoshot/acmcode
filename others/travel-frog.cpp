#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int M=1000000;
double dp[100*100*100+2];
int main(){
    dp[1]=0,dp[2]=2;
    for(int i=3;i<M;++i)
        dp[i]=dp[i-1]+(double)1/(i-1);
    int n;
    while(cin>>n)
    {
        if(n<M) printf("%.7f\n",dp[n]);
        else printf("%.7f\n",log(n-1)+0.577215664901532+1);
    }

    return 0;
}
