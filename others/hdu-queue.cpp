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
 
const int M = 100*1000+10; 
int T,N;
struct poeple
{
    int h,k;
    bool operator < (const poeple & a)
    {
        return h<a.h;
    }
}p[M];
int ans[M];
int cnt[M];
int cnt_back[M];

void ad(int x)
{
    int tx=N-x+1;
    while(tx<=N)
        ++cnt_back[tx],tx+=lb(tx);
    while(x<=N)
        ++cnt[x],x+=lb(x);
}

int get(int x)
{
    int re=0;
    while(x)
        re+=cnt[x],x-=lb(x);
    return re;
}

int get_back(int x)
{
    int re=0;
    while(x)
        re+=cnt_back[x],x-=lb(x);
    return re;
}

int fd(int k)
{
    if(get(N)+k>N) return -1;
    int lo=1,hi=N;
    int mid=(lo+hi)>>1;
    while(lo<hi)
    {
        int re=get(mid);
        if(re+k<=mid)
            hi=mid;
        else
            lo=mid+1;
        mid=(lo+hi)>>1;
    }
    return hi;
}

int from_back(int k)
{
    if(get_back(N)+k>N) return -1;
    int lo=1,hi=N;
    int mid=(lo+hi)>>1;
    while(lo<hi)
    {
        int re=get_back(mid);
        if(re+k<=mid)
            hi=mid;
        else
            lo=mid+1;
        mid=(lo+hi)>>1;
    }
    return N+1-hi;
}


 
int main() 
{ 
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        memset(cnt,0,sizeof(cnt));
        memset(cnt_back,0,sizeof(cnt_back));
        printf("Case #%d: ",i);
        scanf("%d",&N);
        for(int i=0;i<N;++i)
            scanf("%d%d",&p[i].h,&p[i].k);
        sort(p,p+N);
        int pos;
        for(int i=0;i<N;++i)
        {
            pos=fd(p[i].k+1);
            if(-1==pos) break;
            pos=min(pos,from_back(p[i].k+1));
            ans[pos]=p[i].h;
            ad(pos);
        }
        if(-1==pos)
        {
            printf("impossible\n");
            continue;
        }
        for(int i=1;i<N;++i)
            printf("%d ",ans[i]);
        printf("%d\n",ans[N]);
    }
    return 0; 
} 

