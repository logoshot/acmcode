#include<iostream>
#include<set>
#include<string>
#include<cstdio>
#include<cstring>
#define M 350005
#define r(rt) ((rt<<1)+1)
#define l(rt) (rt<<1)

using namespace std;
const int inf=1<<30;
int mi[M*4],cool[M*4],f[M*4];
int cnt[M];
char s[M];

void push_down(int rt)
{
    if(cool[rt])
    {
        mi[r(rt)]+=cool[rt]; 
        mi[l(rt)]+=cool[rt];
        f[r(rt)]+=cool[rt];
        f[l(rt)]+=cool[rt];
        cool[r(rt)]+=cool[rt];
        cool[l(rt)]+=cool[rt];
        cool[rt]=0;
    }
}

void build(int rt,int l,int r)
{
    cool[rt]=0;
    if(l==r)
    {
        f[rt]=cnt[l]-l;
        mi[rt]=cnt[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l(rt),l,mid);
    build(r(rt),mid+1,r);
    mi[rt]=min(mi[l(rt)],mi[r(rt)]);
    f[rt]=max(f[l(rt)],f[r(rt)]);
}

void update(int rt,int l,int r,int ad,int le,int ri)
{
    if(l!=r) push_down(rt);
    if(l==le&&ri==r)
    {
        cool[rt]=ad;
        f[rt]+=ad;
        mi[rt]+=ad;
        return ;
    }
    int mid=(l+r)>>1;
    if(le>mid) update(r(rt),mid+1,r,ad,le,ri);
    else if(ri<=mid) update(l(rt),l,mid,ad,le,ri);
    else 
    {
        update(l(rt),l,mid,ad,le,mid);
        update(r(rt),mid+1,r,ad,mid+1,ri);
    }
    mi[rt]=min(mi[l(rt)],mi[r(rt)]);
    f[rt]=max(f[l(rt)],f[r(rt)]);
}

int find_(int rt,int l,int r)
{
    if(l==r) return l;
    push_down(rt);
    int mid=(l+r)>>1;
    if(f[r(rt)]==0)
        return find_(r(rt),mid+1,r);
    return find_(l(rt),l,mid);
}


int find__(int rt,int l,int r)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    push_down(rt);
    if(mi[r(rt)]<2)
        return find__(r(rt),mid+1,r);
    return find__(l(rt),l,mid);
}

int main()
{
    int n,q,t;
    while(EOF!=scanf("%d%d",&n,&q)){
    scanf("%s",s);
    int cur=0;
    for(int i=0;i<n;++i)
        if(s[i]=='(')
        {
            cnt[i+1]=++cur;
        }        
        else
            cnt[i+1]=--cur;
    build(1,1,n);
    for(int i=0;i<q;++i)
    {
        scanf("%d",&t);
        if(t==1)
        {
            printf("1\n");
            continue;
        }
        if(s[t-1]=='(')
        {
            s[t-1]=')';
            update(1,1,n,-2,t,n);
            int fir=find_(1,1,n);
            s[fir]='(';
            update(1,1,n,2,fir+1,n);
            printf("%d\n",fir+1);
        }
        else
        {
            s[t-1]='(';
            update(1,1,n,2,t,n);
            int rr=find__(1,1,n);
            s[rr]=')';
            update(1,1,n,-2,rr+1,n);
            printf("%d\n",rr+1);
        }
    }
    }
    return 0;
}
