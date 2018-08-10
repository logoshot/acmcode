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
 
const int M = 10*1000+10; 
struct edge
{
    double rate,cms;
    int nx;
    int from;
    int to;
    bool vis;
}e[M];
double v;
int cnt=0;
int head[M]={0};
int n,m,s;
bool ms,an; // if ms==true answer is no    an==true,answer is yes
double dis[M];

void add(int from,int to,double r,double c)
{
    e[++cnt].nx=head[from], e[cnt].rate=r, e[cnt].cms=c, e[cnt].to=to, e[cnt].vis=0;
    e[cnt].from=from;
    head[from]=cnt;
}

bool relax(int from,int i)
{
    if(dis[e[i].to]<(dis[from]-e[i].cms)*e[i].rate)
    {
        dis[e[i].to]=(dis[from]-e[i].cms)*e[i].rate;
        return true;
    }
    return false;
}

bool solve()
{
    dis[s]=v;
    for(int i=1;i<n;++i)
        for(int j=1;j<=cnt;++j)
            relax(e[j].from,j);

    //queue<int> que;
    //que.push(s);
    //while(!que.empty())
    //{
        //int cur=que.front();
        //que.pop();
        //for(int i=head[cur];i!=-1;i=e[i].nx)
        //{
            //if(!e[i].vis)
            //{
                //e[i].vis=true;
                //que.push(e[i].to);
            //}
            //relax(cur,i);
        //}
    //}
    for(int i=1;i<=cnt;++i)
        if(relax(e[i].from,i))
            return true;
    return false;
}

//bool dfs(double cur,int pi)
//{
    //for(int i=head[pi];i!=-1;i=e[i].nx)
    //{
        //if(cur<e[i].cms) return false;
        //if(e[i].vis) 
        //{
            //if(cur>e[i].pre) return true;
        //}
        //else
        //{
            //e[i].vis=true, e[i].pre=cur;
            //if(dfs((cur-e[i].cms)*e[i].rate,e[i].to))
                //return true;
        //}
    //}
    //return false;
//}
 
int main() 
{ 
    memset(head,-1,sizeof(head));
    memset(dis,0,sizeof(dis));
    //scanf("%d%d%d%f",&n,&m,&s,&v);
    cin>>n>>m>>s>>v;
    int a,b;
    double  rab,cab,rba,cba;
    for(int i=0;i<m;++i)
    {
        cin>>a>>b>>rab>>cab>>rba>>cba;
        //scanf("%d%d%f%f%f%f",&a,&b,&rab,&cab,&rba,&cba);
        add(a,b,rab,cab);
        add(b,a,rba,cba);
    }
    if(solve()) printf("YES\n");
    else printf("NO\n");
    return 0; 
} 

