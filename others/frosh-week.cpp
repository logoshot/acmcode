#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int M=200*2000+5;
int work[M];
int iv[M];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,m;
    while(EOF!=scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;++i) scanf("%d",&work[i]);
        for(int i=0;i<m;++i) scanf("%d",&iv[i]);
        sort(work,work+n,cmp);
        sort(iv,iv+m,cmp);
        int j=0;
        int ans=0;
        for(int i=0;i<m;++i)
        {
            while(j<n&&work[j]>iv[i])
                ++j;
            if(n==j) break;
            ++ans;
            ++j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
