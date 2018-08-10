#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls rt<<1
#define rs rt<<1|1
#define inf 0x3f3f3f3f

using namespace std;

const int M=200000+10;
int ans[M];
struct seg
{
    int id,cover,l,r,lazy;
}t[M<<2];

void push_down(int rt)
{
    if(t[rt].lazy)
    {
        t[ls].lazy+=t[rt].lazy;
        t[rs].lazy+=t[rt].lazy;
        t[rs].cover-=t[rt].lazy;
        t[ls].cover-=t[rt].lazy;
        t[rt].lazy=0;
    }
}

void push_up(int rt)
{
    t[rt].id=t[ls].cover>=t[rs].cover?t[rs].id:t[ls].id;
    t[rt].cover=min(t[ls].cover,t[rs].cover);
}

void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r;
    t[rt].lazy=0;
    if(l==r)
    {
        t[rt].cover=t[rt].id=l;
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}

void update(int rt,int l,int r)
{
    if(t[rt].l==l&&t[rt].r==r)
    {
        --t[rt].cover;
        ++t[rt].lazy;
        return ;
    }
    push_down(rt);
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<l) update(rs,l,r);
    else if(mid>=r) update(ls,l,r);
    else
    {
        update(ls,l,mid);
        update(rs,mid+1,r);
    }
    push_up(rt);
}

void change(int rt,int tar)
{
    if(t[rt].r==t[rt].l)
    {
        t[rt].cover=inf;
        return;
    }
    push_down(rt);
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<tar) change(rs,tar);
    else change(ls,tar);
    push_up(rt);
}

int main()
{
    int n,a,b;
    while(EOF!=scanf("%d",&n))
    {
        memset(ans,0,sizeof(ans));
        build(1,1,n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&a,&b);
            if(a)
                update(1,b,n);
            else 
                update(1,1,b);
            if(t[1].cover>0) continue;
            while(!t[1].cover)
            {
                ans[t[1].id]=i+1;
                change(1,t[1].id);
            }
        }
        for(int i=1;i<=n;++i)
            printf("%d ",ans[i]?ans[i]:-1);
        printf("\n");
    }
    return 0;
}
