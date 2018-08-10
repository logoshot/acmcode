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
#define max(a,b) a>b?a:b
 
using namespace std; 
 
const int M = 1000*1000+10; 
int n;
double dis[205][205];
struct point
{
    int x,y;
}p[205];

double cal_dis(int i,int j)
{
    return sqrt((double)(p[i].x-p[j].x)*(p[i].x-p[j].x)+(double)(p[i].y-p[j].y)*(p[i].y-p[j].y));
}

const double mm = 1000000000;

double dijkstra()
{
    bool vis[205]={0};
    for(int i=1;i<n;++i)
        dis[0][i] = cal_dis(0,i); 
    for(int i=1;i<n;++i)
    {
        int cur=0;
        double ma = 100000000;
        for(int i=1;i<n;++i)
            if(!vis[i] && dis[0][i] < ma)
                cur = i,ma=dis[0][i];
        vis[cur]=1;
        for(int i=1;i<n;++i)
            if(!vis[i]&&dis[0][i]>(max(dis[0][cur],cal_dis(cur,i))))
                    dis[0][i] = (max(dis[0][cur],cal_dis(cur,i)));
    }
    return dis[0][1];
}


 
int main() 
{ 
    int testcase=1;
    while(cin>>n)
    {
        double ans;
        if(0==n) break;
        for(int i=0;i<n;++i)
        {
            cin>>p[i].x>>p[i].y;
        }
        ans = dijkstra();
        cout<<"Scenario #"<<testcase++<<endl<<"Frog Distance = ";
        printf("%.3lf\n\n",ans);
        //cout<<setiosflags(ios::fixed)<<setprecision(3)<<ans<<endl<<endl;
    } 
    return 0; 
} 

