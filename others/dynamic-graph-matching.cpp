#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long

using namespace std;
const int mod=1000*1000*1000+7;
ll dp[1030];
ll ans[6]={0};
int t,n,m;

int get(int i)
{
    int re=0;
    while(i)
    {
        if(i&1) ++re;
        i>>=1;
    }
    return re;
}

bool have(int i,int u,int v)
{
    if((i&(1<<u)) && (i&(1<<v)))
        return true;
    return false;
}

void update(int op,int u,int v)
{
    int nn=1<<n;
    int t;
    for(int i=1;i<=nn;++i)
    {
        if(have(i,u,v))
        {
            t=get(i);
            if(t&1) continue;
            dp[i]+=(dp[i-(1<<u)-(1<<v)])*op;
            ans[t/2]+=(dp[i-(1<<u)-(1<<v)])*op;
            dp[i]%=mod;
            ans[t/2]%=mod;
            while(dp[i]<0) dp[i]+=mod;
            while(ans[t/2]<0) ans[t/2]+=mod;
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        scanf("%d%d",&n,&m);
        int u,v;
        char c[2];
        dp[0]=1;
        int op;
        for(int i=0;i<m;++i)
        {
            scanf("%s%d%d",c,&u,&v);
            --u,--v;
            op= c[0]=='+' ? 1 : -1;
            update(op,u,v);
            for(int j=1;j<n/2;++j)
                printf("%lld ",ans[j]);
            printf("%lld\n",ans[n/2]);
        }
    }
    return 0;
}
