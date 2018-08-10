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
const int MM=10000;
int n,k;
int num[MM];
int gr[MM];
int ori[MM];
int tp=0;

void swa(int ww[MM],int a,int b)
{
    int tt=ww[a];
    ww[a]=ww[b],ww[b]=tt;
}


int dfs(int a[])
{
    int ret=inf;
    for(int i=0;i<tp;++i)
    {
        if(a[i]!=ori[i])
        {
            for(int j=i+1;j<tp;++j)
                if(a[j]==ori[i]&&ori[j]!=a[j])
                {
                    swa(a,i,j);
                    ret=min(ret,dfs(a));
                    swa(a,i,j);
                }
            return ret+1;
        }
    }
    return 0;
}

int coun(int c[MM])
{
    int a[100];
    for(int i=0;i<tp;++i)
        a[i]=c[i];
    return dfs(a);
}

bool cmp(int a,int b)
{
    return a>b;
}

void solvemin()
{
        sort(num,num+tp);
        int fr=0;
        while(num[fr]==0) fr++;
        swa(num,fr,0);
        do
        {
            if(coun(num)<=k) break;
        }while(next_permutation(num,num+tp));
        for(int i=0;i<tp;++i)
            cout<<num[i];
        cout<<" ";
}

void solvemax()
{
        sort(num,num+tp,cmp);
        do
        {
            if(coun(num)<=k)
                break;
        }while(prev_permutation(num,num+tp));
        for(int i=0;i<tp;++i)
            cout<<num[i];
        cout<<endl;
}

 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s>>k;
        tp=s.size();
        for(int i=tp-1,j=0;i>-1;++j,--i)
        {
            ori[i]=num[j]=s[i]-'0';
        }

        solvemin();
        solvemax();
    } 
    return 0; 
} 


 
