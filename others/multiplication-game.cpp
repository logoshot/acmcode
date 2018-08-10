#include<cstdio>
#include<iostream>
using namespace std;

long long pr[100000];
bool is_prime(long long i)
{
    if(i&1==0) return false;
    for(long long j=3;j*j<=i;j+=2)
        if(i%j==0) return false;
    return true;
}
void make_prime()
{
    pr[0]=2,pr[1]=3;
    long long k=2;
    for(long long i=5;i<1000*500+5;i+=2)
        if(is_prime(i))
            pr[k++]=i;
}

// first win:  return 1       second win:0     else :-1
int solve(long long n)
{
    int a[100]={0},tp=0;
    for(long long i=0;pr[i]*pr[i]<=n;++i)
    {
        while(0==n%pr[i]) 
        {
            ++a[tp];
            n/=pr[i];
        }
        if(a[tp]) ++tp;
    }
    if(n>1) a[tp++]=1;
    if(tp>2) return -1;
    if(tp==1) return a[0]&1;
    if(a[0]-a[1]==1||-1==a[0]-a[1]) return 1;
    if(a[0]==a[1]) return 0; 
    if(a[0]+a[1]==2) return 0;
    return -1;
}

int main()
{
    make_prime();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        char s[10];
        scanf("%d%s",&n,s);
        int ans=0;
        if(s[0]=='A') ans=1;
        int re=solve(n);
        if(-1==re) cout<<"tie"<<endl;
        else 
        {
            ans=ans^(!re);
            if(ans) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
    }
    return 0;
}
