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
 
using namespace std; 
 
const int M = 1000*1000+10; 
const unsigned int mod = 1<<30;
unsigned int x,y,z,w;
int n,m,T;
inline unsigned int rng()
{
    x = (x^(x<<11));
    x = (x^(x>>4));
    x = (x^(x<<5));
    x = (x^(x>>14));
    w = (x^(y^z));
    x = y;
    y = z;
    z = w; 
    return z;
}

unsigned int st[20][100005];
 
int main() 
{ 
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        memset(st,0,sizeof(st));
        cin>>n>>m>>x>>y>>z;
        unsigned int fa,fb,fc,l,r,v;
        for(int i=0;i<m;++i)
        {
            fa=rng();
            fb=rng();
            fc=rng();
            fa = fa%n + 1, fb = fb%n + 1;
            l = min(fa, fb);
            r = max(fa, fb);
            v = fc%mod;
            int oo=log(r-l+1)/log(2);
            st[oo][l] = max(st[oo][l],v), st[oo][r-(1<<oo)+1] = max(st[oo][r-(1<<oo)+1],v);
        }
        for(int i=17;i>0;--i)
            for(int j=1;j<=n;++j)
            {
                st[i-1][j]=max(st[i-1][j],st[i][j]);
                st[i-1][j+(1<<(i-1))] = max(st[i-1][j+(1<<(i-1))],st[i][j]);
            }
        ll ans=0;
        for(ll i=1;i<=n;++i)
            ans ^= (i*st[0][i]);
        cout<<ans<<endl;
    }
    return 0; 
} 

