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
struct edge
{
    int from,to,val;
    int nx;
}e[10000];
int head[105];
int cnt;
int rk[105];
int pri[105];
int M,N,P,L,X,T,V;
int ans;
int dis[105];


void add(int a,int b,int v)
{
    e[cnt].from = a, e[cnt].to = b, e[cnt].val = v;
    e[cnt].nx = head[a];
    head[a] = cnt++;
}
 
void dfs(int cur,int up,int down)
{
    for(int i=head[cur]; i != -1; i = e[i].nx)
    {
        int to = e[i].to;
        if(rk[to]>up||rk[to]<down) continue;
        if(dis[to] <= dis[e[i].from] + e[i].val - pri[e[i].from] +pri[to])
            continue;
        dis[to] = dis[e[i].from] + e[i].val - pri[e[i].from] +pri[to];
        ans = min(ans, dis[to]);
        dfs(to,min(up, rk[to]+M), max(down,rk[to]-M)); 
    }
}
 
int main() 
{ 
    ios::sync_with_stdio(false);
    cin>>M>>N;
        cnt=0;
        memset(head,-1,sizeof(head));
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=N;++i)
        {
            cin>>P>>L>>X;
            pri[i] = P;
            rk[i] = L;
            for(int j=0;j<X;++j)
            {
                cin>>T>>V;
                add(i,T,V);
            }
        }
        dis[1]=pri[1];
        ans = pri[1];
        dfs(1,rk[1]+M, rk[1]-M);
        cout<<ans<<endl;
    return 0; 
} 

