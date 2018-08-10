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
 
using namespace std; 
 
const int M = 50*1000+10; 
int T,N,a[M];
ll sum[M];

void upd(int i,int d)
{
    while(i<=N)
    {
        sum[i]+=d;
        i+=lb(i);
    }
}

ll get(int i)
{
    ll re=0;
    while(i)
        re+=sum[i],i-=lb(i);
    return re;
}

ll get_sum(int l,int r)
{
    return get(r)-get(l-1);
}

void init()
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=N;++i)
        upd(i,a[i]);
}
 
int main() 
{ 
    scanf("%d",&T);
    for(int tt=1;tt<=T;++tt)
    {
        printf("Case %d:\n",tt);
        scanf("%d",&N);
        for(int i=1;i<=N;++i)
            scanf("%d",&a[i]);
        init();
        char s[10];
        int i,j;
        scanf("%s",s);
        while(s[0]!='E')
        {
            scanf("%d%d",&i,&j);
            if('A'==s[0]) upd(i,j);
            if('S'==s[0]) upd(i,-j);
            if('Q'==s[0]) printf("%lld\n",get_sum(i,j));
            scanf("%s",s);
        }
    }
    return 0; 
} 

