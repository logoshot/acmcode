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
bool ans[120][13][35];
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleapyear(int y)
{
    if(0==y%4&&y!=1900) return true;
    return false;
}

void add(int y[3],int m[3],int d[3])
{
    m[2]= m[0]==12 ? 1 : m[0]+1;
    y[2]= m[0]==12 ? y[0]+1 : y[0];
    d[2]= d[0];

    if(isleapyear(y[0])) month[2]=29;
    d[1]= d[0]==month[m[0]] ? 1 : d[0]+1;
    m[1]= d[0]==month[m[0]] ? m[0]+1 : m[0];
    y[1]=y[0];
    if(13==m[1]) m[1]=1,y[1]=y[0]+1;
    month[2]=28;
}

void sub(int y[3],int m[3],int d[3])
{
    if(isleapyear(y[0])) month[2]=29;
    if(d[0]>1) --d[0];
    else
    {
        if(m[0]==1) m[0]=12,--y[0];
        else --m[0];
        d[0] = month[m[0]];
    }
    month[2]=28;
}

void init()
{
    memset(ans,1,sizeof(ans));
    ans[2001-1900][11][4]=0;
    int y[3],m[3],d[3];
    y[0]=2001,m[0]=11,d[0]=3;
    while(y[0]!=1900||m[0]!=1||d[0]!=1)
    {
        add(y,m,d);
        ans[y[0]-1900][m[0]][d[0]]=(ans[y[1]-1900][m[1]][d[1]]==0||0==ans[y[2]-1900][m[2]][d[2]]) ? 1 : 0;
        sub(y,m,d);
    }
}
 
int main() 
{ 
    init();
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(ans[a-1900][b][c]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0; 
} 

