#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

const int inf=1<<30;
int ans=inf;

int lcs(vector<int>& a,vector<int>& b,int n)
{
    vector<int> dp(n,0);
    int pre=0,t;
    for(int i=0;i<n;++i)
    {
        pre=dp[0]=max(dp[0],a[i]==b[0]?1:0);
        for(int j=1;j<n;++j)
        {
            t=dp[j];
            dp[j]=max(max(pre+(a[i]==b[j]),dp[j]),dp[j-1]);
            pre=t;
        }
    }
    return dp[n-1];
}

void add(vector<vector<int>>& re,int a[4],vector<int>& t)
{
    int j=0;
    for(int i=0;i<4;++i)
        for(int k=0;k<re[a[i]].size();++k)
            t[j++]=re[a[i]][k];
}

bool cmp(int a,int b)
{
    return a>b;
}

void solve(vector<vector<int>>& re, vector<int>& ori,int n,int cur)
{
    if(cur==4)
    {
        int a[4]={0,1,2,3};
        do
        {
            vector<int> t(n);
            add(re,a,t);
            ans=min(ans,n-lcs(t,ori,n));
        }while(next_permutation(a,a+4));
        return;
    }
    if(re[cur].empty())
    {
        solve(re,ori,n,cur+1);
        return;
    }
    sort(re[cur].begin(),re[cur].end());
    solve(re,ori,n,cur+1);
    sort(re[cur].begin(),re[cur].end(),cmp);
    solve(re,ori,n,cur+1);
}

int main()
{
    int n;
    map<char,int> mm;
    char tt[100]="shdc23456789TJQKA";
    for(int i=0;i<18;++i)
        mm[tt[i]]=i;
    while(cin>>n)
    {
        ans=inf;
        char s[3];
        vector<vector<int>> re(4);
        vector<int> ori(n);
        for(int i=0;i<n;++i)
        {
            cin>>s;
            int w=mm[s[0]]+mm[s[1]]*20;
            re[mm[s[1]]].push_back(w);
            ori[i]=w;
        }
        solve(re,ori,n,0);
        cout<<ans<<endl;
    }
    return 0;
}
