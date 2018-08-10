#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b&&(a+b)!=0)
    {
        int ans=a*30+b*40;
        ans=min(ans,a*35+b*30);
        ans=min(ans,a*40+b*20);
        cout<<ans<<endl;
    }
    return 0;
}
