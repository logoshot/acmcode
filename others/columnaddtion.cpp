#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n;
    int a[1005],b[1005],tar[1005];
    cin>>n;
    while(n)
    {
        string sa,sb,star;
        cin>>sa>>sb>>star;
        int re=0,com=0;
        for(int i=0;i<n;++i) a[i]=sa[i]-'0',b[i]=sb[i]-'0',tar[i]=star[i]-'0';
        for(int i=n-1;i>=0;--i)
        {
            if(a[i]+b[i]==tar[i]) ++com;
            if(re)
            {
                if(a[i]+b[i]+1==tar[i]) com=max(re+1,com);
                if(a[i]+b[i]+1==tar[i]+10) ++re;
            }
            if(a[i]+b[i]==tar[i]+10) re=max(com+1,re); 
        }
        cout<<n-com<<endl;
        cin>>n;
    }
    return 0;
}
