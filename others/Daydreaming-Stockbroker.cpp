#include<iostream>
#define ll long long 
using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll cur;
    cin>>cur;
    ll p;
    ll ans=100,all=0;
    while(--n)
    {
        cin>>p;
        if(p>cur){
            ll d=ans/cur;
            all+=d;
            if(all>100000) d-=(all-100000),all=100000;
            ans-=cur*d;
        }
        if(p<cur)
        {
            ans+=cur*all;
            all=0;
        }
        cur=p;
    }
    ans+=all*cur;
    cout<<ans<<endl;
    return 0;
}
