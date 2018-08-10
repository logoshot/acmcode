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
 
using namespace std; 
 
const int M = 1000*1000+10; 
int N;
int t[M];

void upd(int i,int d)
{
    while(i)
        t[i]+=d,i-=lb(i);
}

int get(int i)
{
    int re=0;
    while(i<=N)
        re+=t[i],i+=lb(i);
    return re;
}
 
int main() 
{ 
    scanf("%d",&N);
    while(N)
    {
        memset(t,0,sizeof(t));
        int a,b;
        for(int i=0;i<N;++i)
        {
            scanf("%d%d",&a,&b);
            upd(a-1,-1);
            upd(b,1);
        }
        for(int i=1;i<N;++i)
            printf("%d ",get(i));
        printf("%d\n",get(N));
        scanf("%d",&N);
    }
    return 0; 
} 

