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
 
const int M = 300*1000+10; 
struct tim
{
    int ti,id;
}t[M];
struct peo
{
    int d,r;
}p[M];
int n,m;
int cnt=0;
int root[M];
struct tree
{
    int rson,lson;
    ll sum;
    int num;
}tr[M*20];

bool cmp(tim& a,tim& b)
{
    return a.ti==b.ti?a.id<b.id:a.ti>b.ti;
}

void build(int& rt,int l,int r)
{
    rt=cnt++;
    tr[rt].num=tr[rt].sum=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(tr[rt].lson,l,mid);
    build(tr[rt].rson,mid+1,r);
}

void update(int& rt,int l,int r,int tar,int val,int pre)
{
    rt=cnt++;
    if(l==r) 
    {
        tr[rt].sum=val;
        tr[rt].num=1;
        return;
    }
    tr[rt].lson=tr[pre].lson, tr[rt].rson=tr[pre].rson;
    int mid=(l+r)>>1;
    if(tar>mid) update(tr[rt].rson,mid+1,r,tar,val,tr[pre].rson);
    else update(tr[rt].lson,l,mid,tar,val,tr[pre].lson);
    tr[rt].sum=tr[tr[rt].lson].sum+tr[tr[rt].rson].sum;
    tr[rt].num=tr[tr[rt].lson].num+tr[tr[rt].rson].num;
}

int query(int rt,int l,int r,int need,int sub)
{
    if((ll)need>tr[rt].sum-(ll)sub*tr[rt].num)
        return 0;
    if(l==r)
    {
        if(tr[rt].sum-sub>=(ll)need) return l;
        return 0;
    }
    int mid=(l+r)>>1;
    ll left = tr[tr[rt].lson].sum - (ll)sub*tr[tr[rt].lson].num;
    if((ll)need<=left) return query(tr[rt].lson,l,mid,need,sub);
    return query(tr[rt].rson,mid+1,r,need-left,sub);
}




int  rrr[M];

int check(int need,int sub)
{
    for(int i=1;i<=m;++i)
    {
        if(rrr[i]>sub)
            need-=rrr[i],need+=sub;
        if(need<=0) return i;
    }
    return 0;
}


 
int main() 
{ 
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&t[i].ti);
        t[i].id=i;

        rrr[i]=t[i].ti;
    }
    sort(t+1,t+1+m,cmp);
    build(root[0],1,m);
    for(int i=1;i<=m;++i)
    {
        update(root[i],1,m,t[i].id,t[i].ti,root[i-1]);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&p[i].d,&p[i].r);
        int hi=m,lo=1;
        int mid=(hi+lo)>>1;
        while(hi>lo)
        {
            if(t[mid].ti<=p[i].d)
                hi=mid;
            else
                lo=mid+1;
            mid=(hi+lo)>>1;
        }
        if(lo>m) lo=m;
        if(t[lo].ti<p[i].d) --lo;
        int re=query(root[lo],1,m,p[i].r,p[i].d);
        //if(check(p[i].r,p[i].d)!=re) cout<<"NO"<<endl;
        printf("%d ",re);
    }
    return 0; 
} 

