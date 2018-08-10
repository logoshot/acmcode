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
int cnt=0;
int ans;
int gcd(int a,int b)
{
    if(0==b) return a;
    ++cnt;
    return gcd(b,a%b);
}

int dfs(int a,int b,int cn)
{
    if(1==cn) return 1;
    if(2==cn) 
    {
        if(a==a%b+b) return 0;
        return 1;
    }
    if(a==a%b+b) return !dfs(b,a%b,cn-1);
    return 1;
}
 
int main() 
{ 
    int a,b;
    while(cin>>a>>b)
    {
        if(0==a) break;
        if(a<b)
        {
            int t=a;
            a=b,b=t;
        }
        cnt=0;
        gcd(a,b);
        ans=dfs(a,b,cnt);
        if(ans) cout<<"Stan wins"<<endl;
        else cout<<"Ollie wins"<<endl;
    }
    return 0; 
} 

