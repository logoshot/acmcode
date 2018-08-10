#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int ans;
         if(b>a)
         {
             ans=b-a;
         }
         else
         {
             ans=360-a+b;
         }
         if(ans>180) ans-=360;
         cout<<ans<<endl;
    }
    return 0;
}
