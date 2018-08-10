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
#define lb(x) (x&(-x)) 
#define ls (rt<<1) 
#define rs (rt<<1|1) 
 
using namespace std; 
 
ll n,m;
ll num[20];
ll fi[11];
ll ans;
ll cnt;
ll aa[11];

ll gcd(ll a,ll b)
{
    return b==0? a: gcd(b,a%b);
}

ll gg(ll a,ll b)
{
    ll gc=gcd(a,b);
    return a*b/gc;
}

void choose(int cur,int all,int pre)
{
    if(pre==all)
    {
        ll com=aa[0];
        for(int i=1;i<pre;++i)
            com = gg(com,aa[i]);
        if(all&1) ans+=(n/com);
        else ans-=(n/com);
        return ;
    }
    for(int i=cur;i<=cnt-all+pre;++i)
    {
        aa[pre]=fi[i];
        choose(i+1,all,pre+1);
    }
}
 
int main() 
{ 
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        --n;
        cnt=ans=0;
        for(int i=0;i<m;++i)
        {
            cin>>num[i];
        }
        for(int i=0;i<m;++i)
            for(int j=0;j<m;++j)
                if(i!=j&&num[j]!=0&&num[i]%num[j]==0) num[i]=0;
        sort(num,num+m);
        for(int i=0;i<m;++i)
            if(num[i]) fi[cnt++]=num[i];
        for(int i=0;i<cnt;++i)
        {
            choose(0,i+1,0);
        }
        cout<<ans<<endl;
    }
    return 0; 
} 

