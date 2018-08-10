#include<iostream>
#include<cstdio>

#define ll long long
#define lc(rt) (rt<<1)
#define rc(rt) ((rt<<1)+1)

const int M=100*1000+5;
ll v[M];
int n,q;
ll lazy[M*4]={0};

struct nn
{
    int l,r;
    ll su;
}t[M*4];

void push_down(int rt)
{
    if(!lazy[rt]) return;
    if(t[rt].l==t[rt].r) return;
    t[lc(rt)].su+=lazy[rt]*(t[lc(rt)].r-t[lc(rt)].l+1);
    t[rc(rt)].su+=lazy[rt]*(t[rc(rt)].r-t[rc(rt)].l+1);
    lazy[lc(rt)]+=lazy[rt];
    lazy[rc(rt)]+=lazy[rt];
    lazy[rt]=0;
}

void build(int rt,int left, int right)
{
    t[rt].l=left,t[rt].r=right;
    if(left==right){
        t[rt].su=v[left];
        return ;
    }
    int mid=(left+right)>>1;
    build(lc(rt),left,mid);
    build(rc(rt),mid+1,right);
    t[rt].su=t[lc(rt)].su+t[rc(rt)].su;
}

void update(int rt,int left,int right,ll d)
{
    push_down(rt);
    t[rt].su+=d*(right-left+1);
    if(t[rt].l==left&&t[rt].r==right)
    {
        lazy[rt]+=d;
        return;
    } 
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<left) update(rc(rt),left,right,d);
    else if(right<=mid) update(lc(rt),left,right,d);
    else {
        update(lc(rt),left,mid,d);
        update(rc(rt),mid+1,right,d);
    }
}

ll query(int rt,int left,int right)
{
    push_down(rt);
    if(t[rt].l==left&&t[rt].r==right)
    {
        return t[rt].su;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<left) return query(rc(rt),left,right);
    if(mid>=right) return query(lc(rt),left,right);
    return query(lc(rt),left,mid)+query(rc(rt),mid+1,right);
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)
        scanf("%lld",&v[i+1]);
    build(1,1,n);
    int a,b,d;
    char c[2];
    for(int i=0;i<q;++i)
    {
        scanf("%s",c);
        if(c[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(1,a,b));
        }
        else 
        {
            scanf("%d%d%d",&a,&b,&d);
            update(1,a,b,d);
        }
    }
    return 0;
}

