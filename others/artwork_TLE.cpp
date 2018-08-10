#include<map>
#include<iostream>
#include<cstdio>

using namespace std;
int n,m,q;
int grid[1005][1005]={0};
int a,b,c,d;
int bea=1;
int cnt[1000000]={0};
int cur=2;

bool check()
{
    int le=0,ri=0,up=0,dw=0;    
    for(int i=b-1;i<d+1;++i){
        if(0==grid[a-1][i]) up=1;
        if(0==grid[c+1][i]) dw=1;
    }
    for(int i=a;i<=c;++i)
    {
        if(0==grid[i][b-1]) le=1;
        if(0==grid[i][d+1]) ri=1;
    }
    if(le+ri+up+dw!=0) return false;
    return true;
}

void change(map<int,int>& mm)
{
    for(int i=a;i<=c;++i)
        for(int j=b;j<=d;++j)
        {
            if(grid[i][j]==0) continue;
            mm[grid[i][j]]+=1;
            --cnt[grid[i][j]];
            if(!cnt[grid[i][j]]) --bea;
            grid[i][j]=0;
        }
}

int bfs(int i,int j,int co)
{
    if(i<1||j<1||i>n||j>m) return 0;
    if(grid[i][j]!=co) return 0;
    grid[i][j]=-co;
    int ans=1;
    ans+=bfs(i+1,j,co);
    ans+=bfs(i-1,j,co);
    ans+=bfs(i,j+1,co);
    ans+=bfs(i,j-1,co);
    return ans;
}

void bf(int i,int j,int co)
{
    if(i<1||j<1||i>n||j>m) return ;
    if(grid[i][j]!=co) return ;
    grid[i][j]=-co;
    bf(i+1,j,co);
    bf(i-1,j,co);
    bf(i,j+1,co);
    bf(i,j-1,co);
}

void bfs_ch(int i,int j,int co,int to)
{
    if(i<1||j<1||i>n||j>m) return ;
    if(grid[i][j]!=co) return ;
    grid[i][j]=to;
    bfs_ch(i+1,j,co,to);
    bfs_ch(i-1,j,co,to);
    bfs_ch(i,j+1,co,to);
    bfs_ch(i,j-1,co,to);
}

void dd(map<int,int>& mm ,int i,int j)
{
    if(grid[i][j]!=0&&mm[grid[i][j]])
    {
        int re=bfs(i,j,grid[i][j]);
        bf(i,j,grid[i][j]);
        if(re!=cnt[grid[i][j]]) 
        {
             cnt[cur]+=re;
             cnt[grid[i][j]]-=re;
             bfs_ch(i,j,grid[i][j],cur);
             ++cur;
             ++bea;
         }
         else mm[grid[i][j]]-=0;
    }

}

void cal(map<int,int>& mm)
{
    if(a>1) {
        for(int i=b;i<=d;++i)
            dd(mm,a-1,i);
    }
    if(c<n) for(int i=b;i<=d;++i) 
                dd(mm,c+1,i);
    if(b>1)
        for(int i=a;i<=c;++i)
            dd(mm,i,b-1);
    if(d<m)
        for(int i=a;i<=c;++i)
            dd(mm,i,d+1);
}

int main()
{
    scanf("%d%d%d",&m,&n,&q);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            grid[i][j]=1;
    cnt[1]=n*m;
    while(q--)
    {
        scanf("%d%d%d%d",&b,&a,&d,&c);
        map<int,int> mm;
        change(mm);
        if(check()){
            cout<<bea<<endl;
            continue;
        }
        cal(mm);
        cout<<bea<<endl;
    }
    return 0;
}
