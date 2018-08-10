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

bool is(char c)
{
    if(c=='+'||c=='*') return true;
    return false;
}

bool change(string & s,int i)
{
    if(i==s.size()-1) return true;
    if(is(s[i+1])) return true;
    if(s[i+1]!='?') return false;
    s[i+1]='+';
    return true;
}

bool judge(string & s)
{
    if(s[0]=='+'||s[0]=='*') return false;
    if(s[0]=='0') 
        if(!change(s,0)) return false;
    for(int i=1;i<s.size();++i)
    {
        if(is(s[i])&&is(s[i-1])) return false;
        if(s[i]=='0'&&is(s[i-1]))
            if(!change(s,i))
                return false;
    }
    if(is(s[s.size()-1])) return false;
    for(int i=0;i<s.size();++i)
        if('?'==s[i]) 
            s[i]='1';
    return true;
}
 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(!judge(s)) cout<<"IMPOSSIBLE"<<endl;
        else cout<<s<<endl;
    }
    return 0; 
} 

