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
#define es 1e-8
 
using namespace std; 
 
const int M = 1000*1000+10; 
const double pi=acos(-1);
int m,R;
double ans;

void solve()
{
    //scanf("%d%d",&m,&R);
    cin>>m>>R;
    ans=pi*R*2;
    for(int i=0;i<m;++i)
    {
        int x,y,r;
        cin>>x>>y>>r;
        //scanf("%d%d%d",&x,&y,&r);
        double l=sqrt((double)x*x+y*y);
        //if( fabs(R*1.0-r-l)<es)
        //{
            //ans += pi*2*r;
            //continue;
        //}
        if(R+r<l || R-r>l) continue;
        double arc=acos((R*R+x*x+y*y-r*r)*(double)1/(l*R*2));
        ans-=arc*2*R;
        arc=acos((r*r+x*x+y*y-R*R)*(double)1/(l*r*2));
        ans+=arc*r*2;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(15)<<ans<<endl;
}
 
int main() 
{ 
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }        
    return 0; 
} 

