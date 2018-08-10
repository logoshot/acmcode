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
#define eps 1e-4
 
using namespace std; 
 
const int M = 1000*1000+10; 
 
double g = 9.8;
int main() 
{ 
    ios::sync_with_stdio(false);
    int t,a,b,x,y;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x>>y;
        x = -x;
        double h = y - b*x*1.0/a;
        if(h<eps)
        {
            cout<<"0"<<endl;
            continue;
        }
        double sino = (double)b / sqrt(a*a+b*b);
        double tim = sqrt(h*2.0/g)*2;
        double tt=tim;
        int ans=1;
        double len = sqrt(a*a+b*b)*(double)x/a;
        double fir = sqrt(2.0*g*h)*sino;
        double sec = g/2*sino;
        while(fir*tt+sec*tt*tt<len)
            ++ans,tt+=tim;
        cout<<ans<<endl;
    }
    return 0; 
} 

