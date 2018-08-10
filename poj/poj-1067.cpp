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
const double x= (sqrt(5)+1)*1.0/2;

int judge(int a)
{
    int k=a/x;
    if(k*x==a) return k;
    if((int)((k+1)*x)==a) return k+1;
    return -1;
}
 
int main() 
{ 
    int a,b;
    while(cin>>a>>b)
    {
        if(b<a) 
        {
            int t=a;
            a=b,b=t;
        }
        int re=judge(a);
        int ans=1;
        if(-1!=re&&re+a==b)
            ans=0;
        cout<<ans<<endl;
    }
    return 0; 
} 

