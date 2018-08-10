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
 
const int M = 200*1000+10; 
int t,n;
int ans[M],tp;
int temp[M];

struct point
{
    int id;
    ll x,y;
}p[M];


bool cmp(point a,point b)
{
    if(a.x!=b.x) return a.x<b.x;
    if(a.y!=b.y) return a.y>b.y;
    return a.id<b.id;
}

int judge(point a,point b,point c)
{
    ll re=(b.x-a.x)*c.y+a.x*b.y-b.x*a.y+(a.y-b.y)*c.x;
    if(0==re) return 0;
    ll tx,ty;
    if(a.y>b.y) tx=a.x,ty=a.y+1;
    else tx=b.x,ty=b.y+1;
    ll si=(b.x-a.x)*ty+a.x*b.y-b.x*a.y+(a.y-b.y)*tx;
    if(re>0&&si>0) return 1;
    if(re<0&&si<0) return 1;
    return -1;
}
 
int main() 
{ 
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            p[i].id=i+1;
            scanf("%lld%lld",&p[i].x,&p[i].y);
        }
        if(2==n) 
        {
            printf("1 2\n");
            continue;
        }
        sort(p+1,p+n-1,cmp);
        for(int i=1;i<n-2;++i)
        {
            if(p[i].x==p[i+1].x)
            {
                if(p[i+1].y<p[i].y)
                {
                    p[i+1].y=p[i].y,p[i+1].id=p[i].id;
                }
                if(p[i+1].y==p[i].y)
                    p[i+1].id=min(p[i].id,p[i+1].id);
                p[i].x=inf;
            }
        }
        sort(p+1,p+n,cmp);
        tp=-1;
        ans[++tp]=0;
        int re;
        int post=2;
        int cur=1;
        while(n!=p[cur].id)
        {
            re=judge(p[ans[tp]],p[post],p[cur]);
            if(0==re)
            {
                if(p[cur].id>p[post].id) re=-1;
                else re=1;
            }
            if(1==re) ans[++tp]=cur,cur=post++;
            if(-1==re)
            {
                if(tp) cur=ans[tp--];
                else cur=post++;
            }
        }
        for(int i=0;i<=tp;++i)
            printf("%d ",p[ans[i]].id);
        printf("%d\n",n);
    }
    return 0; 
} 

