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
 
const int M = 50*1000+10; 
int N,Q;
int a[M];
int bt[11][11][M];

int get(int l,int k)
{
    if(l%k==0) return k;
    return l%k;
}

void add(int x,int s[],int c)
{
    while(x)
        s[x]+=c,x-=lb(x);
}

void upd(int l,int r,int k,int c)
{
    int tr=get(l,k);
    add(r,bt[k][tr],c);
    add(l-1,bt[k][tr],-c);
}

int query(int x)
{
    int re=0;
    for(int i=1;i<11;++i)
    {
        int rr=get(x,i);
        for(int j=x;j<=N;j+=lb(j))
            re+=bt[i][rr][j];
    }
    return re;
}


 
int main() 
{ 
    while(EOF!=scanf("%d",&N))
    {
        memset(bt,0,sizeof(bt));
        for(int i=1;i<=N;++i)
            scanf("%d",&a[i]);
        scanf("%d",&Q);
        for(int i=0;i<Q;++i)
        {
            int op;
            scanf("%d",&op);
            if(1==op)
            {
                int l,r,k,c;
                scanf("%d%d%d%d",&l,&r,&k,&c);
                upd(l,r,k,c);
            }
            else
            {
                int x;
                scanf("%d",&x);
                printf("%d\n",query(x)+a[x]);
            }
        }
    }
    return 0; 
} 

