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
int v[100];
 
int main() 
{ 
    int n;
    while(cin>>n)
    {
        int ans=0;
        for(int i=0;i<n;++i)
        {
            cin>>v[i];
            ans^=v[i];
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0; 
} 

