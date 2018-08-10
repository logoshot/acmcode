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
 
const int MM = 1000*1000+10; 
int ma[505][505];
int dis[505];
int F,M,N,W,S,E,T;
int cnt;
struct edge
{
    int from,to,tim;
}e[20000];

bool solve()
{
    cnt=0;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            if(ma[i][j]!=inf)
                e[cnt].from = i, e[cnt].to = j, e[cnt++].tim = ma[i][j];
    for(int i=0;i<N-1;++i)
    {
        bool flag = true;
        for(int j=0;j<cnt;++j)
            if(dis[e[j].from] + e[j].tim < dis[e[j].to])
            {
                dis[e[j].to] = dis[e[j].from] + e[j].tim;
                flag = false;
            }
        if(flag) break;
    }
    for(int j=0;j<cnt;++j)
        if(dis[e[j].from] + e[j].tim < dis[e[j].to])
            return true;
    return false;
}
 
int main() 
{ 
    ios::sync_with_stdio(false);
    cin>>F;
    while(F--)
    {
        memset(ma,0x3f,sizeof(ma));
        memset(dis,0x3f,sizeof(dis));
        dis[1] = 0;

        cin>>N>>M>>W;
        for(int i=0;i<M;++i)
        {
            cin>>S>>E>>T;
            ma[S][E] = min(ma[S][E],T);
            ma[E][S] = min(ma[E][S],T);
        }
        for(int i=0;i<W;++i)
        {
            cin>>S>>E>>T;
            ma[S][E] = min(ma[S][E],-T);
        }

        if(solve())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0; 
} 

