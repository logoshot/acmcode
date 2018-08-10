#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char dot;
    int a,b;
    int n,num;
    cin>>n;
    while(n--)
    {
        cin>>num>>a>>dot>>b;
        double p=600*1000.0/(a*100*100+b);
        printf("%.4f %.4f %.4f\n",(num-1)*p,num*p,(num+1)*p);
    }
    return 0;
}
