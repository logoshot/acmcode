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
int a[200],b[200];
int n,T,m;

int get(int ha,int i)
{
    if(a[i]==0) return 0;
    int t=0;
    int sum=a[i]+b[i];
    if(ha>sum) t+=(ha/sum)*a[i],ha=ha-(ha/sum)*sum;
    t+=min(a[i],max(ha-b[i],0));
    return t;
}


int mm(int ha)
{
    int re=0,num=0;
    for(int i=0;i<n;++i)
    {
        int t=get(ha,i);
        if(t>re) 
            re=t,num=i;
    }
    if(re) a[num]=b[num]=0;
    return re;
}

int mmm(int ha)
{
    int re=0,num=0;
    for(int i=0;i<n;++i)
    {
        int w=get(m,i);
        w=m-w;
        int t=ha-w;
        if(t>re) 
            re=t,num=i;
    }
    if(re) a[num]=b[num]=0;
    return re;
}
 
int main() 
{ 
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%d%d",&a[i],&b[i]);
        int re=mm(m);
        int ans=0;
        while(re)
        {
            ++ans;
            re=mm(re);
        }
        printf("%d\n",ans);
    }
    return 0; 
} 
