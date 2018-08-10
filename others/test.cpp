#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

const int M=500*1000+5;
struct tree
{
    int l,r;
    vector<int> dis;
}t[M*4];
int v[M];

void merge(vector<int>& a,vector<int>& b,vector<int>& ans )
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l1=a.size(),l2=b.size();
    int i=0,j=0;
    while(i<l1&&j<l2)
    {
        if(a[i]==b[j]) ++i,++j;
        else if(a[i]<b[j]){
            ans.push_back(a[i++]);
        }
        else ans.push_back(b[j++]);
    }
    while(i<l1) ans.push_back(a[i++]);
    while(j<l2) ans.push_back(b[j++]);
}

void build(int rt,int l,int r)
{
    t[rt].l=l,t[rt].r=r;
    if(l==r)
    {
        t[rt].dis.push_back(v[l-1]);
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    merge(t[rt<<1].dis,t[rt<<1|1].dis,t[rt].dis);
}

void query(int rt,int l,int r,vector<int>& ans)
{
    if(t[rt].l==l&&t[rt].r==r)
    {
        ans.assign(t[rt].dis.begin(),t[rt].dis.end());
        return;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    if(mid<l) query(rt<<1|1,l,r,ans);
    else if(mid>=r) query(rt<<1,l,r,ans);
    else
    {
        vector<int> a,b;
        query(rt<<1,l,mid,a);
        query(rt<<1|1,mid+1,r,b);
        merge(a,b,ans);
    }
}

int main()
{
    int n,q;
    for(int i=0;i<1000;++i)
    {
        n=rand()%200+1;
        for(int j=0;j<n;++j)
            v[j]=rand()+1;
        for(int i=1;i<=1000;++i) t[i].dis.clear();
        build(1,1,n);
        for(int j=0;j<20;++j)
        {
            int a=rand()%n+1,b=a+rand()%n;
            while(b>n) b=a+rand()%n;
            vector<int> ans;
            query(1,a,b,ans);
            if(ans.empty()) continue;
            int cnt=0;
            for(int w=a-1;w<b;++w)
                if(v[w]==ans[0]) ++cnt;
            if(cnt>1) 
            {
                cout<<"Case :";
                for(int k=0;k<n;++k)
                    cout<<v[k]<<" ";
                cout<<endl<<a<<" "<<b<<" "<<ans[0]<<endl;
            }
        }
    }
/*    scanf("%d",&n);*/
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
    /*}*/
    return 0;
}
