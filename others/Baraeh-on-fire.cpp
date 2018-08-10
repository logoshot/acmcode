#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define inf 0x3f3f3f3f
using namespace std;

int t[105][105];
char f[105][105];
int n,m,k;
int sx,sy,tx,ty,fx,fy;
int stk[1000100],tp=0,he=0;

void add(int x,int y)
{
    int ne=t[x][y]+k;
    for(int i=-1;i<2;++i)
        for(int j=-1;j<2;++j)
        {
            if(0==i&&0==j) continue;
            if(x+i>=n||x+i<0||y+j<0||y+j>=m) continue;
            if(t[x+i][y+j]!=0&&f[x+i][y+j]=='f')
            {
                t[x+i][y+j]=0;
                stk[tp++]=x+i;stk[tp++]=y+j;
            }
            if(ne<t[x+i][y+j])
            {
                stk[tp++]=x+i;stk[tp++]=y+j;t[x+i][y+j]=ne;
            }
        }
}

void bfs(int x,int y)
{
    t[x][y]=0;
    tp=he=0;
    stk[tp++]=x;stk[tp++]=y;
    while(he!=tp)
    {
        add(stk[he],stk[he+1]);
        he+=2;
    } 
}

int step[105][105];
int aa[4]={0,0,-1,1},bb[4]={-1,1,0,0};
void ad(int x,int y)
{
    int ne=step[x][y]+1;
    for(int ww=0;ww<4;++ww)
        {
            int i=aa[ww],j=bb[ww];
            if(x+i>=n||x+i<0||y+j<0||y+j>=m) continue;
            if(ne>=t[x+i][y+j]) continue;
            if(ne<step[x+i][y+j])
            {
                stk[tp++]=x+i;stk[tp++]=y+j;step[x+i][y+j]=ne;
            }
        }
}


void bf(int x,int y)
{
    step[x][y]=0;
    he=tp=0;
    stk[tp++]=x;stk[tp++]=y;
    while(he!=tp)
    {
        ad(stk[he],stk[he+1]);
        he+=2;
    } 
}

int main()
{
    cin>>n>>m>>k;
    while(n)
    {
        memset(t,inf,sizeof(t));
        memset(step,inf,sizeof(step));
        fx=fy=-1;
        for(int i=0;i<n;++i) cin>>f[i];
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                if(f[i][j]=='s') sx=i,sy=j;
                if(f[i][j]=='t') tx=i,ty=j;
                if(f[i][j]=='f') fx=i,fy=j;
            }
        if(fx==-1){
            cout<<abs(sx-tx)+abs(sy-ty)<<endl;
            cin>>n>>m>>k;
            continue;
        }
        bfs(fx,fy);
        bf(sx,sy); 
        if(step[tx][ty]==inf) cout<<"Impossible"<<endl;
        else cout<<step[tx][ty]<<endl;
        cin>>n>>m>>k;
    }
    return 0;
}
