#include<iostream>
#define mii(a,b) a>b?b:a
using namespace std;

const int m=100*1000+5;
struct tree
{
    int l,r,mi;
}t[m*4];
int v[m];
int n,q;
char s[m];

void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r;
    if(l==r)
    {
        t[rt].mi=v[l-1];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    t[rt].mi=mii(t[rt<<1].mi,t[rt<<1|1].mi);
}

int query(int rt,int l , int r)
{
    if(t[rt].l==l&&t[rt].r==r)
    {
        return t[rt].mi;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<l) return query(rt<<1|1,l,r);
    if(mid>=r) return query(rt<<1,l,r);
    return mii(query(rt<<1,l,mid),query(rt<<1|1,mid+1,r));
}

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        scanf("%s",s);
        v[0]=1;
        for(int i=1;i<n;++i)
            if(s[i]=='(')
                v[i]=v[i-1]+1;
            else v[i]=v[i-1]-1;
        build(1,1,n);
        int a,b;
        for(int i=0;i<q;++i)
        {
            scanf("%d%d",&a,&b);
            if(b<a)
            {
                int ww=a;
                a=b,b=ww;
            }
            if(s[a-1]=='('&&s[b-1]==')')
            {
                int re=query(1,a,b-1);
                if(re<2) printf("No\n");
                else printf("Yes\n");
            }
            else printf("Yes\n");
        }
    }
    return 0;
}
