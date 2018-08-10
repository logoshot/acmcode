#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        int his;
        cin>>his;
        int a=s[0]-'0',b=0;//wrong rule:a  true : b
        for(int i=1;i<s.size();i+=2)
        {
            if(s[i]=='*') a*=(s[i+1]-'0');
            else a+=(s[i+1]-'0');
        }
        int j=0;
        while(j<s.size())
        {
            int t=s[j]-'0';
            while(j<s.size()-1&&s[j+1]=='*') t*=(s[j+2]-'0'),j+=2;
            j+=2;
            b+=t;
        }
        if(a==his&&b==his) cout<<"U";
        if(a==his&&b!=his) cout<<"L";
        if(a!=his&&b==his) cout<<"M";
        if(a!=his&&b!=his) cout<<"I";
        cout<<endl;
    }
    return 0;
}
