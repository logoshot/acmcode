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
 
int route[105][105];
int dis[105][105];
int N,M,P,L,X,T,V;
bool vis[105];
int rk[105];

int dijkstra()
{
    for(int i=1;i<=N;++i)
        dis[0][i]=route[0][i];
    while(1)
    {
        int flag=1;
        int cur=0,ma=inf;
        for(int i = 1;i <= N;++i)
            if(!vis[i] && dis[0][i]<ma)
                cur=i, ma = dis[0][i] ,flag=0;
        if(flag) break;
        vis[cur] = 1;
        for(int i=1;i<=N;++i)
            if(!vis[i] && dis[0][i] > dis[0][cur] + route[cur][i])
                dis[0][i] = dis[0][cur] + route[cur][i];
    }
    return dis[0][1];
}
 
int main() 
{ 
    memset(route,0x3f,sizeof(route));
    int ans=inf;
    cin>>M>>N;
    for(int i=0;i<N;++i)
    {
        cin>>P>>L>>X;
        route[0][i+1]=P;
        rk[i+1] = L;
        for(int j=0;j<X;++j)
        {
            cin>>T>>V;
            route[T][i+1] = V;
        }
    }
    for(int lowbound = rk[1] - M;lowbound<=rk[1]; ++lowbound)
    {
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=N;++i)
            if(rk[i]<lowbound||rk[i]>lowbound+M)
                vis[i]=1;
        ans = min(ans, dijkstra());
    }
    cout<<ans<<endl;
    return 0; 
} 

