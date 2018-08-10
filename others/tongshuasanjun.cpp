#include<cstdio>
#include<algorithm>
#define ll long long 
#define M 1000005
using namespace std;

struct node
{
    int w,x,y;
}v[M];

bool cmp1(node a,node b)
{
    return a.x<b.x;
}

bool cmp2(node a,node b)
{
    return a.y<b.y;
}

int main()
{
    int n;
    while(EOF!=scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
            scanf("%d",&v[i].w);
        for(int i=0;i<n;++i)
            scanf("%d%d",&v[i].x,&v[i].y);
        ll pre=0,ans=0,post=0;
        sort(v,v+n,cmp1);
        for(int i=0;i<n;++i) post+=v[i].w;
        ll flag=0;
        for(int i=0;i<n;++i)
        {
            pre+=v[i].w,post-=v[i].w;
            if(pre>=post)
            {
                flag=v[i].x;
                break;
            }
        }
        for(int i=0;i<n;++i)
            ans+=(ll)v[i].w*abs(flag-v[i].x);
        sort(v,v+n,cmp2);
        pre=post=flag=0;
        for(int i=0;i<n;++i) post+=v[i].w;
        for(int i=0;i<n;++i)
        {
            pre+=v[i].w,post-=v[i].w;
            if(pre>=post)
            {
                flag=v[i].y;
                break;
            }
        }
        for(int i=0;i<n;++i)
            ans+=(ll)v[i].w*abs(flag-v[i].y);
        printf("%.2f\n",ans*1.0);
    }
    return 0;
}

