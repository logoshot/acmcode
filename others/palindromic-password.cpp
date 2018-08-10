/*#include<iostream>*/
//#include<algorithm>
//using namespace std;
//int main()
//{
    //int pa[900],tp=0;
    //for(int i=1;i<10;++i)
        //for(int j=0;j<10;++j)
            //for(int k=0;k<10;++k)
                //pa[tp++]=i*100*1000+j*100*100+k*1000+k*100+j*10+i;
    //int n;
    //while(cin>>n)
    //{
        //while(n--)
        //{
            //int t;
            //cin>>t;
            //int an=pa[0],m=abs(pa[0]-t);
            //for(int i=1;i<900;++i)
                //if(abs(pa[i]-t)<m) 
                    //an=pa[i],m=abs(pa[i]-t);
            //cout<<an<<endl;
        //}
    //}
    //return 0;

/*}*/

//solution two;
#include<iostream>
#include<algorithm>
using namespace std;
int f(int t)
{
    return t/100000*100001+t/10000%10*10010+t/1000%10*1100;
}
int main()
{
    int n;
    while(cin>>n)
    {
        while(n--)
        {
            int t;
            cin>>t;
            int an=f(t),m=abs(t-an),w=t;
            for(int i=1;i<30;++i)
            {
                t+=1000;
                if(abs(f(t)-w)<=m) 
                {
                    if(abs(f(t)-w)==m) an=min(f(t),an);
                    else an=f(t);
                    m=abs(f(t)-w);
                }
            }
            t=w;
            for(int i=1;i<30;++i)
            {
                t-=1000;
                if(t<=0) break;
                if(abs(f(t)-w)<=m) 
                {
                    if(abs(f(t)-w)==m) an=min(f(t),an);
                    else an=f(t);
                    m=abs(f(t)-w);
                }
           }
            cout<<an<<endl;
        }
    }
    return 0;
}
