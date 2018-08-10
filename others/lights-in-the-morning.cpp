#include<iostream>
#define ll long long
using namespace std;

int main()
{
    ll n,al;
    while(cin>>n>>al)
    {
        ll x,a,g,r;
        bool flag=1;
        for(int i=0;i<n;++i)
        {
            cin>>x>>a>>g>>r;
            if(x>al) continue;
            if(x<a)
            {
                flag=0;
            }
            ll k=(x-a)/(g+r);
            if(x>g+a+k*(g+r)) 
            {
                flag=0;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } 
    return 0;
}
