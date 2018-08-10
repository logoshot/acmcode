#include<cstdio>
#include<iostream>
#define Max 1500005
using namespace std;

int fa[Max];
struct query
{
    int x,xx,y,yy;
}q[Max];
int n,m,k;
int grid[Max]={0};
int cnt=0;
int ans[Max];

void change_color()
{
    for(int i=1;i<=k;++i)
    {
        for(int j=q[i].x;j<=q[i].xx;++j)
            for(int w=q[i].y;w<=q[i].yy;++w)
                ++grid[j*m+w-m];
    }
}

int find_(int x)
{
    return fa[x]==x?x:fa[x]=find_(fa[x]);
}

void merge(int a,int b)
{
    if(grid[a]||grid[b]) return;
    int f_a=find_(a);
    int f_b=find_(b);
    if(f_a==f_b) return;
    fa[f_a]=f_b; 
    --cnt;
}

void merge_around(int i)
{
    ++cnt;
    if(i>m)
        merge(i,i-m);
    if(i+m<=n*m)
        merge(i,i+m);
    if(i%m!=1) 
        merge(i,i-1);
    if(i%m!=0)
        merge(i,i+1);
}

int main()
{
    while(EOF!=scanf("%d%d%d",&m,&n,&k)){
        cnt=0;
    for(int i=0;i<Max;++i) fa[i]=i,grid[i]=0;
    for(int i=1;i<=k;++i)
    {
        scanf("%d%d%d%d",&q[i].y,&q[i].x,&q[i].yy,&q[i].xx);
    }
    change_color();

    for(int i=1;i<=n*m;++i)
        if(!grid[i]) merge_around(i);
    ans[k]=cnt;
    for(int i=k;i>1;--i)
    {
        for(int j=q[i].x;j<=q[i].xx;++j)
            for(int w=q[i].y;w<=q[i].yy;++w)
            {
                --grid[j*m+w-m];
                if(grid[j*m+w-m]==0)
                    merge_around(j*m+w-m);
            }
        ans[i-1]=cnt;
    }
    for(int i=1;i<=k;++i)
        printf("%d\n",ans[i]);
    }
    return 0;
}
