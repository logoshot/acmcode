#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool oneway(int t[4][4],int i,int j,int co,int g[4][4],int si,int sj)
{
    if(i<0||j<0||i>3||j>3)
        return false;
    if(t[i][j]!=co)
        return false;
    if(g[i][j]==co&&(i!=si||j!=sj))
    {
        t[i][j]=0;
        for(int k=0;k<4;++k)
            for(int w=0;w<4;++w)
                if(t[k][w]==co)
                {
                    t[i][j]=co;
                    return false;
                }
        t[i][j]=co;
        return true;
    }
    t[i][j]=0;
    if(oneway(t,i-1,j,co,g,si,sj)) {t[i][j]=co;return true;}
    if(oneway(t,i+1,j,co,g,si,sj)) {t[i][j]=co;return true;}
    if(oneway(t,i,j-1,co,g,si,sj)) {t[i][j]=co;return true;}
    if(oneway(t,i,j+1,co,g,si,sj)) {t[i][j]=co;return true;}
    t[i][j]=co;
    return false;
}

bool check(int t[4][4],int g[4][4],int al)
{
    int w,i,j;
    for(int k=2;k<=al;++k)
    {
        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
                if(g[i][j]==k)
                    break;
            if(g[i][j]==k) break;
        }
        if(!oneway(t,i,j,t[i][j],g,i,j))
            return false;
    }
    return true;
}

bool color(int g[4][4],int al,int t[4][4],int cur)
{
    if(16==cur)
    {
        return check(t,g,al);
    } 
    int i=cur/4,j=cur%4;
    if(g[i][j]>1) return color(g,al,t,cur+1);
    for(int k=2;k<=al;++k)
    {
        t[i][j]=k;
        if(color(g,al,t,cur+1))
            return true;
    }
    return false;
}

int main()
{
    char gr[5][5];// W:1  R: 2 G:3  B:4 Y: 5
    while(cin>>gr[0])
    {
        cin>>gr[1]>>gr[2]>>gr[3];
        int g[4][4];
        int flag=0;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                switch (gr[i][j])
                {
                    case 'W': g[i][j]=1;break;
                    case 'R': g[i][j]=2;break;
                    case 'G': g[i][j]=3;break;
                    case 'B': g[i][j]=4;break;
                    default : g[i][j]=5;flag=1;
               }
        int t[4][4];
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                t[i][j]=g[i][j];
        if(color(g,4+flag,t,0))
            cout<<"solvable"<<endl;
        else cout<<"not solvable"<<endl;
    }

    return 0;
}
