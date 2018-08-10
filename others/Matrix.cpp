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
int X,T,N;
int sum[1005][1005];

void change(int x,int y)
{
    for(int i=x;i;i-=lb(i))
        for(int j=y;j;j-=lb(j))
            ++sum[i][j];
}

int query(int x,int y)
{
    int ans=0;
    for(int i=x;i<=N;i+=lb(i))
        for(int j=y;j<=N;j+=lb(j))
            ans+=sum[i][j];
    return ans&1;
} 
int main() 
{ 
    scanf("%d",&X);
    while(X--)
    {
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&N,&T);
        for(int t=0;t<T;++t)
        {
            char c[10];
            scanf("%s",c);
            if('C'==c[0])
            {
                int l,b,r,t;
                scanf("%d%d%d%d",&l,&b,&r,&t);
                change(l-1,b-1);
                change(r,t);
                change(l-1,t); change(r,b-1);
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",query(x,y));
            }
        }
        if(X) printf("\n");
    }
    return 0; 
} 

