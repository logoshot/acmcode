/*********************** 
 c++ file 
***********************/

#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<iostream>  
#include<string>  
#include<vector>  
#include<stack>  
#include<bitset>  
#include<cstdlib>  
#include<cmath>  
#include<set>  
#include<list>  
#include<deque>  
#include<map>  
#include<queue>  

#define ls (rt<<1)
#define rs (rt<<1|1)

using namespace std;
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 0x3fffffff;  
const int maxn = 100;  
const ll two = 1<<30;
const int M=100000+10;
ll a[100010];
ll re=0;
unsigned int n,m;

unsigned int x,y,z,w;

unsigned int rng61(){
    x = (x^(x<<11)),x = (x^(x>>4)),x = (x^(x<<5)),x = (x^(x>>14)),w = (x^(y^z)),x = y,y = z,z = w;
    return z;
}

struct tree
{
    int val;
    int l,r,lazy;
    int up;
    int minn;
}t[M*4];

void push_down(int rt)
{
    if(t[rt].lazy!=-1)
    {
        if(t[rt].lazy>t[ls].val)
        {
            t[ls].val=t[rt].lazy,t[ls].lazy=t[rt].lazy;
        }
        if(t[rt].lazy>t[rs].val)
        {
            t[rs].val=t[rt].lazy,t[rs].lazy=t[rt].lazy;
        }
        t[rt].lazy=-1;
    }
}
void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r,t[rt].up=0;
    t[rt].val=t[rt].minn=0;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}

void update(int rt,int l,int r,int v)
{
    if(t[rt].l==t[rt].r) 
    {
        t[rt].val=t[rt].minn=max(v,t[rt].val);
        return;
    }
    if(v<=t[rt].minn) return ;
    if(t[rt].l==l&&t[rt].r==r)
    {
        if(v>=t[rt].val) 
        {
            t[rt].up=1,t[rt].val=t[rt].minn=v;
            return;
        }
    }
    if(t[rt].up)
    {
        t[ls].up=t[rs].up=1;
        t[rs].minn = t[ls].minn = t[ls].val=t[rs].val=t[rt].val;
    }
    t[rt].up=0;
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<l) update(rs,l,r,v);
    else if(mid>=r) update(ls,l,r,v);
    else 
    {
        update(ls,l,mid,v);
        update(rs,mid+1,r,v);
    }
    t[rt].minn=min(t[ls].minn,t[rs].minn);
    t[rt].val=max(t[ls].val,t[rs].val);
}

int query(int rt,int tar)
{
    if(t[rt].up) return t[rt].val;
    if(t[rt].l==t[rt].r) return t[rt].val;
    int mid=(t[rt].l+t[rt].r)>>1;
    if(tar>mid) return query(rs,tar);
    return query(ls,tar);
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--){
        unsigned int l,r,v;
        unsigned int f1,f2,f3;
        scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
        build(1,1,n);
        for(int i=1;i<=m;i++){
            f1 = rng61();
            f2 = rng61();
            f3 = rng61();
            f1%=n,f2%=n;
            ++f1,++f2;
            l = (f1)<(f2)?(f1):(f2);
            r = (f1)>(f2)?(f1):(f2);
            v = f3%two;
            update(1,l,r,v);
            //for(int j=l;j<=r;j++){
                //if(a[j]<v){
                    //a[j] = (ll)v;
                //}
            //}
        }
        re = 0;
        for(ll i=1;i<=n;i++){
            re = (re^(i*query(1,i)));
        }
        printf("%lld\n",re);
    }
}
