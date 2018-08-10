#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define pii pair<int,int>

using namespace std;

const int M=500*1000+5;
const int inf=1<<30;
int pre[M];
int rm[M]={0};
int v[M];
int pk=0;
struct st
{
    int l,r,mi;
}t[M*4];

void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}

void update(int rt,int tar)
{
    if(t[rt].l==t[rt].r)
    {
        t[rt].mi=tar;
        return;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    if(tar>mid) update(rt<<1|1,tar);
    else update(rt<<1,tar);
    t[rt].mi=pre[t[rt<<1].mi]<pre[t[rt<<1|1].mi]?t[rt<<1].mi:t[rt<<1|1].mi;
}

void to(int tar)
{
    while(pk<tar)
    {
        ++pk;
        if(rm[v[pk]])
        {
            pre[rm[v[pk]]]=inf;
            update(1,rm[v[pk]]);
            pre[pk]=rm[v[pk]];
            rm[v[pk]]=pk;
        }
        else
        {
            rm[v[pk]]=pk;
            pre[pk]=-1;
        }
        update(1,pk);
    }
}

int query(int rt,int l,int r)
{
    if(t[rt].l==l&&t[rt].r==r)
        return t[rt].mi;
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<l) return query(rt<<1|1,l,r);
    if(mid>=r) return query(rt<<1,l,r);
    int a=query(rt<<1,l,mid),b=query(rt<<1|1,mid+1,r);
    return pre[a]<pre[b]?a:b;
}

struct nn
{
    int f,se,order,an;
}ask[M];

bool cmp(nn a,nn b)
{
    return a.se<b.se;
}

bool cm(nn a,nn b)
{
    return a.order<b.order;
}

int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&v[i+1]);
    scanf("%d",&q);
    for(int i=0;i<q;++i)
    {
        ask[i].order=i;
        scanf("%d%d",&ask[i].f,&ask[i].se);
    }
    sort(ask,ask+q,cmp);
    build(1,1,n);
    int mi;
    for(int i=0;i<q;++i)
    {
        to(ask[i].se);
        mi=query(1,ask[i].f,ask[i].se);
        if(pre[mi]<ask[i].f) ask[i].an=v[mi];
        else ask[i].an=0;
    }
    sort(ask,ask+q,cm);
    for(int i=0;i<q;++i)
        printf("%d\n",ask[i].an);
}
/*struct tree*/
//{
    //int l,r;
    //vector<int> dis;
//}t[M*4];
//int v[M];

//void merge(vector<int>& a,vector<int>& b,vector<int>& ans )
//{
    //sort(a.begin(),a.end());
    //sort(b.begin(),b.end());
    //int l1=a.size(),l2=b.size();
    //int i=0,j=0;
    //while(i<l1&&j<l2)
    //{
        //if(a[i]==b[j]) ++i,++j;
        //else if(a[i]<b[j]){
            //ans.push_back(a[i++]);
        //}
        //else ans.push_back(b[j++]);
    //}
    //while(i<l1) ans.push_back(a[i++]);
    //while(j<l2) ans.push_back(b[j++]);
//}

//void build(int rt,int l,int r)
//{
    //t[rt].l=l,t[rt].r=r;
    //if(l==r)
    //{
        //t[rt].dis.push_back(v[l-1]);
        //return;
    //}
    //int mid=(l+r)>>1;
    //build(rt<<1,l,mid);
    //build(rt<<1|1,mid+1,r);
    //merge(t[rt<<1].dis,t[rt<<1|1].dis,t[rt].dis);
//}

//void query(int rt,int l,int r,vector<int>& ans)
//{
    //if(t[rt].l==l&&t[rt].r==r)
    //{
        //ans.assign(t[rt].dis.begin(),t[rt].dis.end());
        //return;
    //}
    //int mid=(t[rt].l+t[rt].r)>>1;
    //if(mid<l) query(rt<<1|1,l,r,ans);
    //else if(mid>=r) query(rt<<1,l,r,ans);
    //else
    //{
        //vector<int> a,b;
        //query(rt<<1,l,mid,a);
        //query(rt<<1|1,mid+1,r,b);
        //merge(a,b,ans);
    //}
//}

//int main()
//{
    //int n,q;
    //scanf("%d",&n);
    //for(int i=0;i<n;++i)
        //scanf("%d",&v[i]);
    //build(1,1,n);
    //scanf("%d",&q);
    //int a,b;
    //for(int i=0;i<q;++i)
    //{
        //scanf("%d%d",&a,&b);
        //vector<int> ans;
        //query(1,a,b,ans);
        //if(ans.empty()) printf("0");
        //else
            //printf("%d",ans[0]);
        //printf("\n");
    //}
    //return 0;
/*}*/
