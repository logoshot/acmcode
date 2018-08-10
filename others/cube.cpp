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
 
int N,M;
int ss[105][105][105];
int xa,xb,ya,yb,za,zb,op;

void upd(int x,int y,int z)
{
    for(int i=x;i;i-=lb(i))
        for(int j=y;j;j-=lb(j))
            for(int k=z;k;k-=lb(k))
                ++ss[i][j][k];
}

void add()
{
    upd(xb,yb,zb);
    upd(xb,ya-1,zb);
    upd(xb,yb,za-1);
    upd(xa-1,yb,zb);
    upd(xa-1,yb,za-1);
    upd(xb,ya-1,za-1);
    upd(xa-1,ya-1,zb);
    upd(xa-1,ya-1,za-1);
}
    
int query()
{
    int ans=0;
    for(int i=xa;i<=N;i+=lb(i))
        for(int j=ya;j<=N;j+=lb(j))
            for(int k=za;k<=N;k+=lb(k))
                ans+=ss[i][j][k];
    return ans&1;
}
 
int main() 
{ 
    while(EOF!=scanf("%d%d",&N,&M))
    {
        memset(ss,0,sizeof(ss));
        for(int i=0;i<M;++i)
        {
            scanf("%d%d%d%d",&op,&xa,&ya,&za);
            if(op)
            {
                scanf("%d%d%d",&xb,&yb,&zb);
                add();
            }
            else
            {
                printf("%d\n",query());
            }
        }
    }
    return 0; 
} 

