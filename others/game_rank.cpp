#include<iostream>
#include<string>
using namespace std;

int ran=25;
int bonus=0;
int star=0;
int need[26];
int main()
{
    for(int i=1;i<11;++i) need[i]=5;
    for(int i=11;i<16;++i) need[i]=4;
    for(int i=16;i<21;++i) need[i]=3;
    for(int i=21;i<26;++i) need[i]=2;
    string s;
    while(cin>>s){
        bonus=0,star=0,ran=25;
    for(int i=0;i<s.size();++i)
    {
        if(0==ran) break;
        if(s[i]=='W'){
            ++star;
            ++bonus;
            if(2<bonus&&ran>5) ++star;
            if(star>need[ran])
                star-=need[ran],--ran;
        }
        else
        {
            bonus=0;
            if(ran>20) continue;
            if(ran==20&&star==0) continue;
            --star;
            if(-1==star) ++ran,star=need[ran]-1; 
        }
    } 
    if(0==ran) cout<<"Legend"<<endl;
    else cout<<ran<<endl;
    } 
    return 0;
}
