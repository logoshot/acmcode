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
int sq[1030][1030];
ll sum[1030][1030];
int S;

void add(int x,int y,int d)
{
    for(int i=x;i<=S;i+=lb(i))
        for(int j=y;j<=S;j+=lb(j))
            sum[i][j]+=d;
}

ll get(int x,int y)
{
    ll re=0;
    for(int i=x;i;i-=lb(i))
        for(int j=y;j;j-=lb(j))
            re+=sum[i][j];
    return re;
}

ll query(int l,int b,int r,int t)
{
    ll re=get(r,t);
    re-=get(r,b-1),re-=get(l-1,t),re+=get(l-1,b-1);
    return re;
}

ll check(int l,int b,int r,int t)
{
    ll re=0;
    for(int i=l;i<=r;++i)
        for(int j=b;j<=t;++j)
            re+=sq[i][j];
    return re;
}

void pri()
{
    for(int i=1;i<=S;++i)
    {
        for(int j=1;j<=S;++j)
            cout<<sum[i][j]<<" ";
        cout<<endl;
    }
}
 
int main() 
{ 
    int op;
    scanf("%d",&op);
    while(op!=3)
    {
        memset(sum,0,sizeof(sum));
        memset(sq,0,sizeof(sq));
        scanf("%d%d",&S,&op);
        while(op!=0&&op!=3)
        {
            if(2==op)
            {
                int l,r,b,t;
                scanf("%d%d%d%d",&l,&b,&r,&t);
                //if(check(l+1,b+1,r+1,t+1)!=query(l+1,b+1,r+1,t+1))
                    //printf("NO");
                printf("%lld\n",query(l+1,b+1,r+1,t+1));
            }
            else 
            {
                int x,y,A;
                scanf("%d%d%d",&x,&y,&A);
                sq[x+1][y+1]+=A;
                add(x+1,y+1,A);
            }
            scanf("%d",&op);
        }
    }
    return 0; 
} 

