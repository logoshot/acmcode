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
 
const int M = 1000*1000+10; 
int n,m;
bool vis[1005]; 
bool ins[1005];
vector<vector<int>> edge(1005);
vector<vector<int>> ne(1005);  // new edge;
int bfn[1005];
int low[1005];
int bfn_value;
int scc;
int stk[1005],tp;
int belong[1005];
int dgr[1005];

void tarjan(int i)
{
    bfn[i] = low[i] = ++bfn_value;
    vis[i] = 1;
    ins[i] = 1;
    stk[tp++] = i;
    for(int j = 0; j<edge[i].size() ; ++j)
    {
        int w=edge[i][j];
        if(!vis[w])
        {
            tarjan(w);
            low[i] = min(low[w], low[i]);
        } 
        else if(ins[w])
        {
            low[i] = min(low[i] ,low[w]);
        }
    }
    if(low[i] == bfn[i])
    {
        ++scc;
        belong[i] = scc;
        ins[i] = 0;
        while(stk[tp-1]!=i)
        {
            belong[stk[--tp]] = scc;
            ins[stk[tp]] = 0;
        }
        --tp;
    }
}

void rebuild()
{
    for(int i=1;i<=n;++i)
    {
        int be = belong[i];
        for(int j=0;j<edge[i].size(); ++j)
        {
            int cur = belong[edge[i][j]];
            if(cur!=be)
            {
                ++dgr[cur];
                ne[be].push_back(cur);
            }
        }
    }
}

bool topo()
{
    int tp=0;
    for(int i=1;i<=scc;++i)
        if(0==dgr[i])
            stk[tp++] = i;
    if(tp>1) return false;
    while(tp)
    {
        int v = stk[--tp];
        for(int i=0;i<ne[v].size(); ++i)
        {
            --dgr[ne[v][i]];
            if(dgr[ne[v][i]]==0)
                stk[tp++] = ne[v][i];
        }
        if(tp>1) return false;
    }
    return true;
}


int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        tp = bfn_value = scc = 0;
        memset(dgr,0,sizeof(dgr));
        memset(vis,0,sizeof(vis));
        memset(ins,0,sizeof(ins));
        memset(belong,0,sizeof(belong));
        scanf("%d%d",&n,&m);
        int u,v;
        for(int i=1;i<=n;++i)
        {
            edge[i].clear();
            ne[i].clear();
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        for(int i=1;i<=n;++i)
            if(!vis[i])
                tarjan(i);

        rebuild();

        if(topo()) printf("I love you my love and our love save us!\n");
        else printf("Light my fire!\n");
    }
    return 0; 
} 

