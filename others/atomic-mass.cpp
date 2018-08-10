#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main()
{
    int a,b;
    char dot;
    int n;
    while(cin>>n)
    {
        string s;
        map<string,int> f;
        while(n--)
        {
            cin>>s>>a;
            cin>>dot;
            cin>>b;
            f[s]=a*100+b;
        }
        cin>>s;
        int ans=0;
        for(int i=0;i<s.size();)
        {
            string t;
            t+=s[i++];
            if(s[i]>='a'&&s[i]<='z') 
                t+=s[i++];
            int num=0;
            while(i<s.size()&&s[i]>='0'&&s[i]<='9')
            {
                num*=10,num+=s[i++]-'0';
            }
            ans+=(num?num*f[t]:f[t]);
        }
//        cout<<(double)ans/100<<endl;
        printf("%.2f",ans*1.00/100);
    }
    return 0;
}
