#include<iostream>
#include<algorithm>
#include<vector>
//#define forn(i,n) for(int i=0;i<n;++i)
#define pii pair<int,int>

using namespace std;

bool cmp(pii a,pii b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main()
{
    int n,m;
    while(cin>>m>>n)
    {
        vector<pii> v(n);
        for(int i=0;i<n;++i) cin>>v[i].first>>v[i].second;
        sort(v.begin(),v.end(),cmp);
        pii cur;
        int i=0;
        int ans=m+1;
        while(i<n)
        {
            cur=v[i++];
            while(i<n&&cur.second>=v[i].first)
            {
                cur.second=max(cur.second,v[i].second);
                ++i;
            }
            ans+=2*(cur.second-cur.first);
        }
        cout<<ans<<endl;
    }
    return 0;
}
