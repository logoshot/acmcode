#include<iostream>
#include<string>
using namespace std;

string in()
{
    string s;
    cin>>s;
   string a;
   int w=3;
   while(w--){
       cin>>a;
       s+=a;
   }
   return s;
}

bool is(string s)
{
    for(int i=0;i<16;++i)
        if(s[i]!='0') return true;
    return false;
}

int main()
{
    string s;
    s=in();
    while(is(s))
    {
        int t[16];
        int sum=0;
        for(int i=0;i<16;++i) t[i]=s[i]-'0';
        for(int i=0;i<16;++i)
        {
            if(i&1) sum+=t[i];
            else{
                int w=t[i]<<1;
                if(w>9) w-=9;
                sum+=w;
            }
        }
        if(sum%10==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        s=in();
    }
    return 0;
}
