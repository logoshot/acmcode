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
int x,X,y,Y;
int T,L,A[15];
int Q;
int a[100][100];
ll sum[100][100];

void make_matrix()
{
    int cursor=0;
    for(int i=0;i<L*8;++i)
        for(int j=0;j<=i;++j){
            a[j][i-j]=A[cursor];
            cursor=(cursor+1)%L;
        }
    sum[0][0]=a[0][0];
    for(int i=1;i<L*8;++i)
        sum[0][i]=sum[0][i-1]+a[0][i];
    ll cur=0;
    for(int i=1;i<8*L;++i)
    {
        cur=0;
        for(int j=0;j<8*L;++j){
            cur+=a[i][j];
            sum[i][j]=sum[i-1][j]+cur;
        }
    }
}

ll get(int i,int j,int l)
{
    int ii=i/l,jj=j/l;
    ll ans=sum[l-1][l-1]*ii*jj;
    i-=(ii*l),j-=(jj*l);
    if(i==0&&j==0) return ans;
    if(j>0) ans+=sum[l-1][j-1]*ii;
    if(i>0) ans+=sum[i-1][l-1]*jj;
    if(i>0&&j>0) ans+=sum[i-1][j-1];
    return ans;
}
 
int main() 
{ 
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&L);
        int l= L&1 ? L : L*2;
        for(int i=0;i<L;++i)
            scanf("%d",&A[i]);
        make_matrix();
        scanf("%d",&Q);
        ll ans;
        for(int i=0;i<Q;++i)
        {
            scanf("%d%d%d%d",&x,&y,&X,&Y);
            ++x,++y,++X,++Y;
            ans=get(X,Y,l)-get(X,y-1,l)-get(x-1,Y,l)+get(x-1,y-1,l);
            printf("%lld\n",ans);
        }
    }
    return 0; 
} 

