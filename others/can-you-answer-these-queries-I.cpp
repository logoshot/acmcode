#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int M=50010;
struct seg
{
    int l,r;
    int mi,ma,be;
}t[M*4];
int n,m;
int a[M];
int sum[M];

void merge(seg& x,seg& y,seg& z)
{
    z.l=x.l,z.r=y.r;
    z.be=max(max(x.be,y.be),y.ma-x.mi);
    z.mi=min(x.mi,y.mi);
    z.ma=max(x.ma,y.ma);
}    

void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r;
    if(l==r) 
    {
        t[rt].mi=min(sum[l],sum[l-1]);
        t[rt].ma=sum[l];
        t[rt].be=a[l-1];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    merge(t[rt<<1],t[rt<<1|1],t[rt]);
}

seg query(int rt,int l,int r)
{
    if(t[rt].l==l&&t[rt].r==r)
        return t[rt];
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<l) return query(rt<<1|1,l,r);
    if(mid>=r) return query(rt<<1,l,r);
    seg aa=query(rt<<1,l,mid),bb=query(rt<<1|1,mid+1,r);
    seg re;
    merge(aa,bb,re);
    return re;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sum[0]=0;
    for(int i=0;i<n;++i)
        sum[i+1]=a[i]+sum[i];
    build(1,1,n);
    scanf("%d",&m);
    int x,y;
    seg re;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&x,&y);
        re=query(1,x,y);
        printf("%d\n",re.be);
    }
    return 0;
}
