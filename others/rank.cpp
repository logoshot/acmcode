/*********************** 
 c++ file 
***********************/

#include<iostream> 
#include<cstdio> 
#include<vector> 
#include<map> 
#include<algorithm> 
#include<string> 
#include<cstring> 
#include<set> 
#include<cmath> 
#include<queue> 
#include<fstream> 
#include<ctime> 
#include<iomanip> 
#include<bitset> 
#include<cstdlib> 
#include<deque> 
#include<list> 
#include<stack> 
#include<utility> 
 
#define ll long long 
#define inf 0x3f3f3f3f 
#define lb(x) (x&(-x)) 
#define ls (rt<<1) 
#define rs (rt<<1|1) 
 
using namespace std; 
 
const int M = 1000*1000+10; 
struct grade
{
    int id,gr;
}p[1005];

bool cmp(grade x,grade y)
{
    if(x.gr==y.gr)
        return x.id<y.id;
    return x.gr>y.gr;
}
 
int main() 

{ 
    int n;
    int a,b,c,d;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b>>c>>d;
        p[i].gr=a+b+c+d;
        p[i].id=i+1;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;++i)
        if(p[i].id==1)
        {
            cout<<i+1<<endl;
            break;
        }

    return 0; 
} 

