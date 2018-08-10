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
#define lb(x) (x&(-x)) 
#define ls (rt<<1) 
#define rs (rt<<1|1) 
 
using namespace std; 
 
const int M = 100*1000+2; 
int n,m;
int fa[M][18];
map<string,int> mp;
int cnt=1;
bool bfa[M];
int deep[M];

int f(int a,int b)
{
    deep[0]=0;
    int ans=0;
    if(deep[a]<deep[b])
    {
        for(int i=19;i>-1;--i)
        {
            if(deep[fa[b][i]]<deep[a]) continue;
            if(deep[fa[b][i]]>deep[a]) 
            {
                b=fa[b][i];
            }
        }
        b=fa[b][0];
    }
    if(deep[b]<deep[a])
    {
        for(int i=17;i>-1;--i)
        {
            if(deep[fa[a][i]]<deep[b]) continue;
            if(deep[fa[a][i]]>deep[b]) 
            {
                a=fa[a][i];
                ans+=(1<<i);
            }
        }
        a=fa[a][0];
    }
    if(a==b) return ans;
    for(int i=17;i>-1;--i)
    {
        if(fa[a][i]==fa[b][i]) continue;
        ans+=(1<<i);
        a=fa[a][i],b=fa[b][i];
    }
    return ans+1;
}

int change(int i,int ff)
{
    if(i==ff) return 1;
    deep[i]=change(fa[i][0],ff);
    return deep[i];
}
 
int main() 
{ 
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        memset(fa,0,sizeof(fa));
        memset(bfa,0,sizeof(bfa));
        cin>>n>>m;
        string sa,sb;
        for(int i=1;i<=n;++i)
            fa[i][0]=i;
        for(int i=1;i<n;++i)
        {
            cin>>sa>>sb;
            if(mp[sa]==0) mp[sa]=cnt++;
            if(mp[sb]==0) mp[sb]=cnt++;
            fa[mp[sa]][0]=mp[sb];
            bfa[mp[sb]]=1;
        }
        int ff;
        for(int i=1;i<18;++i)
            for(int j=1;j<=n;++j)
            {
                fa[j][i]=fa[fa[j][i-1]][i-1];
                if(fa[j][0]==j) ff=j;
            }
        deep[ff]=0;
        for(int i=1;i<=n;++i)
        {
            if(!bfa[i])
            {
                change(i,ff);
            }
        }
        for(int i=0;i<m;++i)
        {
            cin>>sa>>sb;
            int a=mp[sa],b=mp[sb];
            if(a==b) 
            {
                cout<<0<<endl;
                continue;
            }
            int re=f(a,b);
            cout<<re+1<<endl;
        }
    }

    return 0; 
} 

