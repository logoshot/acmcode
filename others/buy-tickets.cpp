#include<iostream>
#include<algorithm>
#include<cstdio>
#define M 200005

using namespace std;
int n;
struct node
{
    int pos,val,ans;
}v[M];

struct tree
{
    int l,r,cn;
}t[M*4];

bool cmp(node a,node b)
{
    return a.ans<b.ans;
}

void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r,t[rt].cn=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}

void update(int rt,int tar)
{
    if(t[rt].l==t[rt].r)
    {
        t[rt].cn=1;
        return ;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    if(tar>mid) update(rt<<1|1,tar);
    else update(rt<<1,tar);
    ++t[rt].cn;
}

int query(int rt,int l,int r)
{
    if(l==t[rt].l&&t[rt].r==r)
        return t[rt].cn;
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<l) return query(rt<<1|1,l,r);
    if(mid>=r) return query(rt<<1,l,r);
    return query(rt<<1,l,mid)+query(rt<<1|1,mid+1,r);
}

int get(int i)
{
    int p=1+v[i].pos;
    int lo=p,hi=n;
    int mid=(lo+hi)>>1;
    int re=query(1,1,mid);
    while(p+re!=mid)
    {
        if(p+re>mid) lo=mid+1;
        else hi=mid;
        mid=(lo+hi)>>1;
        re=query(1,1,mid);
    }
    return mid;
/*    int w=v[i].pos+1;*/
    //int q=query(1,1,w);
    //while(v[i].pos+1!=w-q)
    //{
        //w=q+v[i].pos+1;
        //q=query(1,1,w);
    //}
    /*return w;*/
}

int upd(int rt,int k)
{
    ++t[rt].cn;
    if(t[rt].l==t[rt].r)
        return t[rt].l;
    int ll=t[rt<<1].r-t[rt<<1].l-t[rt<<1].cn+1;
    if(ll>=k)
        return upd(rt<<1,k);
    return upd(rt<<1|1,k-ll);
}

int main()
{
    while(EOF!=scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
            scanf("%d%d",&v[i].pos,&v[i].val);
        build(1,1,n);
        for(int i=n-1;i>-1;--i)
        {
            v[i].ans=upd(1,v[i].pos+1);
/*            update(1,v[i].ans);*/
        }
        sort(v,v+n,cmp);
        for(int i=0;i<n;++i)
            printf("%d ",v[i].val);
        printf("\n");
    }
    return 0;
}

