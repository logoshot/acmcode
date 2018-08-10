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
 
int main() 
{ 
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&n,&a);
        if(1==n)
        {
            printf("0\n");
            continue;
        }
        for(int i=1;i<n;++i)
            scanf("%d",&b);
        printf("%d\n",(int)sqrt(abs(a-b))); 
    }
    return 0; 
} 

