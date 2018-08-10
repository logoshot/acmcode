#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>

using namespace std;

int main()
{
    string s;
    string a="aiyeoubkxznhdcwgpvjqtsrlmf",b="eouaiypvjqtsrlmfbkxznhdcwg";
    map<char,char> p;
    for(int i=0;i<26;++i)
        p[a[i]]=b[i];
    while(getline(cin,s))
    {
        for(int i=0;i<s.size();++i)
        {
            if(s[i]>='a'&&s[i]<='z')
                s[i]=p[s[i]];
            if(s[i]>='A'&&s[i]<='Z')
               s[i]=p[s[i]+32]-32;
        }
        cout<<s<<endl; 
    }
    return 0;
}
