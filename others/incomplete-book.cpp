#include<iostream>
#define ll long long
using namespace std;
int main()
{
    ll n,d;
    while(cin>>n>>d)
    {
        int ans=0;
        while(d>=n)
        {
            ++ans;
            d-=n;
            n<<=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
