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
 
const int M = 50*1000+10; 
int fa[M];
int n,m;
int re;
bool vis[M];
int fi(int x)
{
    return fa[x] = fa[x]==x ? x : fi(fa[x]);
}

void join(int x,int y)
{
    int fx=fi(x),fy=fi(y);
    if(fx!=fy) fa[fx]=fy;
}

void init()
{
    for(int i=1;i<=n;++i)
        fa[i]=i;
}
 
int main() 
{ 
    int ca=1;
    while(scanf("%d%d",&n,&m)&&n)
    {
        init();
        int a,b;
        re=0;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&a,&b);
            join(a,b);
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;++i)
        {
            int f=fi(i);
            if(!vis[f]) ++re,vis[f]=1;
        }
        printf("Case %d: %d\n",ca,re);
        ++ca;
    }
    return 0; 
} 

