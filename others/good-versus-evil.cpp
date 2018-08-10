#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int go[10]={1,2,3,3,4,10};
    int ev[10]={1,2,2,2,3,5,10};
    char ans[3][50]={"Evil eradicates all trace of Good","Good triumphs over Evil","No victor on this battle field"};
    for(int i=1;i<=n;++i)
    {
        int a=0,b=0,t;
        for(int j=0;j<6;++j)
        {
            cin>>t;
            a+=t*go[j];
        }
        for(int j=0;j<7;++j)
        {
            cin>>t;
            b+=t*ev[j];
        }
        cout<<"Battle "<<i<<": ";
        if(a>b) cout<<ans[1];
        if(b>a) cout<<ans[0];
        if(a==b) cout<<ans[2];
        cout<<endl;
    }
    return 0;
    
}
