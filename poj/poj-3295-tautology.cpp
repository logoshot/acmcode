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
string s;
string t;
bool ans;
char c[10]="pqrst";
int stk[1000];
int tp=-1;

bool cal()
{
    tp=-1;
    for(int i=s.size()-1;i>-1;--i)
    {
        if(isdigit(s[i]))
            stk[++tp]=s[i]-'0';
        else if('N'==s[i])
            stk[tp]=!stk[tp];
        else
        {
            if('k'==s[i])
                stk[tp-1]=(stk[tp]&stk[tp-1]);
            if('A'==s[i])
                stk[tp-1]=(stk[tp]|stk[tp-1]);
            if('E'==s[i])
                stk[tp-1]=(stk[tp]==stk[tp-1])? 1 : 0;
            if('C'==s[i])
                stk[tp-1]=(stk[tp]==1&&stk[tp-1]==0)?0:1;
            --tp;
        }
    }
    return stk[0];
}

void change(int k)
{
    if(!ans) return;
    if(5==k)
    {
        if(!cal())
            ans=false;
        return;
    }
    for(int i=0;i<s.size();++i)
        if(c[k]==t[i])
        {
            s[i]='0';
        }
    change(k+1);
    for(int i=0;i<s.size();++i)
        if(c[k]==t[i])
        {
            s[i]='1';
        }
    change(k+1);
}
 
int main() 
{ 
    while(cin>>s)
    {
        t=s;
        ans=true;
        if('0'==s[0]) break;
        change(0);
        if(ans) cout<<"tautology"<<endl;
        else cout<<"not"<<endl;
    }
    return 0; 
} 

