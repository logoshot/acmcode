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
 
const int M = 1000*1000+10; 
const double pi = acos(-1);
 
int main() 
{ 
    ll t,a,b;
    cin>>t;
    while(t--)
    {
        int dig[10];
        cin>>a>>b;
        ll ans=pi*a*1000000+2*b*1000000;
        for(int i=6;i>0;--i)
        {
            dig[i]=ans%10;
            ans/=10; 
        }
        cout<<ans<<".";
        for(int i=1;i<7;++i)
            cout<<dig[i];
        cout<<endl;
    }
    return 0; 
} 

