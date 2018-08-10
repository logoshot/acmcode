#include<iostream>
#define ll long long
using namespace std;

ll eu(ll a)
{
    if(a<4) return a-1;
    ll re=a;
    for(int i=2;i*i<=a;++i)
    {
        if(a%i==0)
        {
            re/=i,re*=(i-1);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) re/=a,re*=(a-1);
    return re;
}

ll mi(ll a,ll b,ll c)
{
    if(b==0) return 1;
    ll t=a%c;
    a=1;
    while(b)
    {
        if(b&1) a*=t;
        a%=c;
        t*=t;
        t%=c;
        b>>=1;
    } 
    return a;
}

ll ex(ll n,ll m)
{
    if(1==m) return 0;
    ll ph=eu(m);
    if(n<3) return n%m;
    if(3==n) return 9%m;
    if(4==n) return (1<<18)%m;
    return mi(n,ex(n-1,ph)+ph,m);
}

int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        cout<<ex(n,m)<<endl;
    }
    return 0;
}
