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
#define ls (rt<<1) 
#define rs (rt<<1|1) 
#define MAXN 100010
 
using namespace std; 
 
const int M = 100*1000+10; 
int n;
char s[M];
char num[12]="0123456789";
char ptn[12];
int myl,myr,ans;
int cur[M];
int lw[M],rw[M];
int tot;


void cal(int a,int b)
{
    lw[n]=rw[n]=rw[0]=lw[0]=cur[0]=0;
    //for(int i=1;i<=n;++i)
        //cur[i] = cur[i-1] + (s[i]==pnt[0]);
    for(int i=0;i<tot+2;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(!i) cur[j]=0;
            if(s[j]==ptn[i])
            {
                cur[j] = cur[j-1] + 1;
                if(i>a) 
                    lw[j] = lw[j-1];
                if(i>b)
                    rw[j] = rw[j-1];
                if(i==a)
                {
                    if(lw[j-1]) 
                        lw[j] = lw[j-1];
                    else 
                        lw[j] = j;
                }
                if(i==b)
                {
                    rw[j] = j;
                }
            }
            else
            {
                if(cur[j]>cur[j-1])
                {
                    if(a==i) 
                        lw[j] = 0;
                    if(b==i)
                        rw[j] = 0;
                }
                else
                {
                    cur[j] = cur[j-1];
                    if(a<=i)
                        lw[j] = lw[j-1];
                    if(b<=i)
                        rw[j] = rw[j-1];
                }
            }
        }
    }
    if(cur[n]>ans)
    {
        ans = cur[n];
        myl = lw[n];
        myr = rw[n];
    }
        
}


void makeptn(int a,int b)
{
    for(int i=0;i<a;++i)
        ptn[i]=num[i];
    ptn[a]=num[a];
    for(int i=a,j=b+1;i<=b;++i,--j)
        ptn[j]=num[i];
    for(int i=b;i<tot;++i)
        ptn[i+2]=num[i];
}


void travel()
{
    int cnt[100];
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;++i)
        ++cnt[s[i]];

    tot=0;
    for(char cc='0';cc<='9';++cc)
        if(cnt[cc]) num[tot++]=cc;

    ans=0;
    makeptn(0,0);
    cal(100,100);
    for(int i=1;i<tot;++i)
    {
        for(int j=0;j<tot-i;++j)
        {
            makeptn(j,j+i);
            cal(j+1,j+i+1);
        }
    }
}
 


int main() 
{ 
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>(s+1);
        travel();
        cout<<ans<<" ";
        if(myl&&myr)
            cout<<myl<<" "<<myr<<endl;
        else
            cout<<"1 1"<<endl;
    }
    return 0; 
} 



