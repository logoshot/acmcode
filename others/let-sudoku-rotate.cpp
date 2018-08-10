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
char sudo[20][20];
int ans;

void rot(int n)
{
    int a=n/4*4,b=n%4*4;
    char t[5][5];
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            t[i][j]=sudo[a+3-j][b+i];
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            sudo[a+i][b+j]=t[i][j];
}

bool check(int k)
{
    for(int i=0;i<k+4;++i)
    {
        bool vis[100]={0};
        for(int j=0;j<16;++j)
            if(vis[sudo[i][j]]) return false;
            else vis[sudo[i][j]]=true;
    }
    for(int i=0;i<16;++i)
    {
        bool vis[100]={0};
        for(int j=0;j<k+4;++j)
            if(vis[sudo[j][i]]) return false;
            else vis[sudo[j][i]]=true;
    }
    return true;
}


void dfs(int k,int cur)
{
    if(16==k)
    {
        ans=min(ans,cur);
        return ;
    }
    for(int i=0;i<4;++i,rot(k))
        for(int j=0;j<4;++j,rot(k+1))
            for(int p=0;p<4;++p,rot(k+2))
                for(int q=0;q<4;++q,rot(k+3))
                {
                    if(!check(k)) continue;
                    if(ans<=cur+i+j+p+q) continue;
                    dfs(k+4,cur+i+j+p+q);
                }
}
 
int main() 
{ 
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<16;++i)
            scanf("%s",sudo[i]);
        //rot(0);
        //for(int i=0;i<16;++i)
            //printf("%s\n",sudo[i]);
        ans=inf;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0; 
} 

