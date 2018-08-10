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
 
const int M = 1000*100+10; 
int N,Q;
struct node
{
    int valuee,id;
}v[M];
int ra[M];

bool cmp(node &a,node &b)
{
    return a.valuee>b.valuee;
}

struct tree
{
    int num;
    int l,r;
}t[M*20];
int cnt;
int root[M];

void build(int& rt,int l,int r)
{
    rt==++cnt;
    t[rt].num=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(t[rt].l,l,mid);
    build(t[rt].r,mid+1,r);
}

void upd(int & rt,int l,int r,int tar,int pre)
{
    rt=++cnt;
    if(l==r) 
    {
        t[rt].num=1;
        return;
    }
    int mid=(l+r)>>1;
    t[rt].l=t[pre].l,t[rt].r=t[pre].r;
    if(mid<tar) upd(t[rt].r,mid+1,r,tar,t[pre].r);
    else upd(t[rt].l,l,mid,tar,t[pre].l);
    t[rt].num=t[t[rt].l].num+t[t[rt].r].num;
}

int query(int lt,int rt,int k,int l,int r)
{
    if(l==r) return v[l].valuee;
    int mid=(l+r)>>1;
    int dd=t[t[rt].l].num-t[t[lt].l].num;
    if(dd>=k)
        return query(t[lt].l,t[rt].l,k,l,mid);
    return query(t[lt].r,t[rt].r,k-dd,mid+1,r);
}
 
int main() 
{ 
    while(scanf("%d%d",&N,&Q)!=EOF)
    {
        cnt=0;
        for(int i=1;i<=N;++i)
        {
            scanf("%d",&v[i].valuee);
            v[i].id=i;
        }
        build(root[0],1,N);
        sort(v+1,v+1+N,cmp);
        for(int i=1;i<=N;++i)
            ra[v[i].id]=i;
        for(int i=1;i<=N;++i)
            upd(root[i],1,N,ra[i],root[i-1]);
            
        int l,r;
        for(int i=0;i<Q;++i)
        {
            scanf("%d%d",&l,&r);
            --l;
            int hi=r-l,lo=1;
            int mid=(hi+lo)>>1;
            while(hi>lo+1)
            {
                if(query(root[l],root[r],mid,1,N)>=mid)
                    lo=mid;
                else
                    hi=mid-1;
                mid=(hi+lo)>>1;
            }
            if(hi==lo+1&&query(root[l],root[r],hi,1,N)>=hi)
            {
                printf("%d\n",hi);
                continue;
            }
            printf("%d\n",lo);
        }
    }
    return 0; 
} 

