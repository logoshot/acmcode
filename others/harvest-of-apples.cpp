/*********************** 
 c++ file 
***********************/

#include<iostream> 
#include<cstdio> 
#include<vector> 
#include<map> 
#include<algorithm> 
#include<string> 
#include<cstring> 
#include<set> 
#include<cmath> 
#include<queue> 
#include<fstream> 
#include<ctime> 
#include<iomanip> 
#include<bitset> 
#include<cstdlib> 
#include<deque> 
#include<list> 
#include<stack> 
#include<utility> 
 
#define ll long long 
#define inf 0x3f3f3f3f 
 
using namespace std; 
 
const int M = 100*1000+10; 
const ll mod=100*1000*10000+7;
int T;
int unit;
int blk[M];
ll ans;
ll fac[M];
ll ni[M];
ll tmp[M];
ll an[M];

void gcd(ll a,ll b,ll &x,ll &y)
{
    if(0==b)
    {
        x=1,y=0;
        return;
    }
    gcd(b,a%b,y,x);
    y-=a/b*x;
}

ll niyuan(ll a,ll b)
{
    ll x,y;
    gcd(a,b,x,y);
    return (x%b+b)%b;
}

void init()
{
    fac[0] = fac[1] = tmp[1] = ni[0] = ni[1] = 1;
    for(int i = 2; i < M; i++) {
        fac[i] = 1ll*fac[i-1]*i%mod;
        tmp[i] = 1ll*(mod-mod/i)*tmp[mod%i]%mod;
        ni[i] = 1ll*ni[i-1]*tmp[i]%mod;
    }
}

struct query
{
    int n,m;
    int id;
    int bll;
    int ans;
}q[M];

bool cmp(query a,query b)
{
    return  blk[a.n]==blk[b.n] ? a.m<b.m : a.n<b.n;
}

bool CMP(query a,query b)
{
    return a.id<b.id;
}

ll C(ll a,ll b)
{
    return fac[b]*ni[a]%mod*ni[b-a]%mod;
}


int main() 
{ 
    init();
    scanf("%d",&T);
    int up=0;
    for(int i=0;i<T;++i)
    {
        scanf("%d%d",&q[i].n,&q[i].m);
        up=max(up,q[i].n);
        q[i].id=i;
    }
    unit=sqrt(M);
    for(int i=1;i<M;++i)
        blk[i]=i/unit;
    sort(q,q+T,cmp);
    ans=0;
    for(int i=0;i<=q[0].m;++i)
        ans+=C(i,q[0].n),ans%=mod;
    an[q[0].id]=ans;
    ll n=q[0].n,m=q[0].m;

    //ans=0;
    //ll n=0,m=0;

    for(int i=0;i<T;++i)
    {
        while(n>q[i].n){ ans+=C(m,--n),ans*=ni[2],ans%=mod;}
        while(n<q[i].n){ ans=ans+ans-C(m,n++)+mod,ans%=mod;}
        while(m<q[i].m){ ans=ans+mod+C(++m,n),ans%=mod;}
        while(m>q[i].m){ ans=ans+mod-C(m--,n),ans%=mod;}
        an[q[i].id]=ans;
    }
    for(int i=0;i<T;++i)
        printf("%lld\n",an[i]);
    return 0; 
} 

