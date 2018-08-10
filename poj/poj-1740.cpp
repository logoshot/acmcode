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
int n;
int st[100];
 
int main() 
{ 
    while(cin>>n)
    {
        if(0==n) break;
        int tp=0;
        int t;
        int ans=1;
        for(int i=0;i<n;++i)
        {
            cin>>t;
            if(t) 
                st[tp++]=t;
        }
        if(tp&1) ans=1;
        else
        {
            if(0==tp) ans=0;
            else
            {
                ans=0;
                sort(st,st+tp);
                for(int i=0;i<tp;i+=2)
                    if(st[i]!=st[i+1])
                        ans=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0; 
} 

