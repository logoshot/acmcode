#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int n,T,m;
int q,s,t,k;
int x,y,ans;
int a[111][55][55],b[211][55][55];

void floyd()
{
    for(int i=2;i<201;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int l=1;l<=n;++l)
            {
                for(int r=1;r<=n;++r)
                {
                    b[i][j][l]=min(b[i][j][l],b[i-1][j][r]+b[1][r][l]);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[1][i][j]=b[100][i][j];
    for(int i=2;i<101;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int l=1;l<=n;++l)
            {
                for(int r=1;r<=n;++r)
                {
                    a[i][j][l]=min(a[i][j][l],a[i-1][j][r]+b[100][r][l]);
                }
            }
        }
    }
    // change b to at least i edge;
    for(int l=1;l<=n;++l)
        for(int r=1;r<=n;++r)
        {
            for(int i=199;i>-1;--i)
            {
                b[i][l][r]=min(b[i][l][r],b[i+1][l][r]);
            }
        }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(b,0x3f,sizeof(b));
        memset(a,0x3f,sizeof(a));
        scanf("%d%d",&n,&m);
        int u,v,w;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            b[1][u][v]=min(b[1][u][v],w);
        }
        floyd();
        scanf("%d",&q);
        for(int i=0;i<q;++i)
        {
            ans=inf;
            scanf("%d%d%d",&s,&t,&k);
            x=(k-1)/100,y=k-100*x;
            for(int j=1;j<=n;++j)
            {
                ans=min(ans,a[x][s][j]+b[y][j][t]);
            }
            if(k<110) ans=b[k][s][t];
            printf("%d\n",ans==inf?-1:ans);
        }
    }
    return 0;
}
