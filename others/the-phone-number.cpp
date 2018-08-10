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
const int ck=9;

int cal_lis(int a[])
{
    int stk[10],tp=0;
    stk[tp++]=a[0];
    for(int i=1;i<ck;++i)
    {
        if(a[i]>stk[tp-1]){
            stk[tp++]=a[i];
            continue;
        }
        else if(a[i]==stk[tp-1]) continue;
        int j=tp-1;
        while(j>-1&&a[i]<stk[j]) --j;
        stk[j+1]=a[i];
    }
    return tp;
}
int cal_lds(int a[])
{
    int stk[10],tp=0;
    stk[tp++]=a[0];
    for(int i=1;i<ck;++i)
    {
        if(a[i]<stk[tp-1]){
            stk[tp++]=a[i];
            continue;
        }
        else if(a[i]==stk[tp-1]) continue;
        int j=tp-1;
        while(j>-1&&a[i]>stk[j]) --j;
        stk[j+1]=a[i];
    }
    return tp;

}
void check()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    do
    {
        int lis=cal_lis(a);
        int lds=cal_lds(a);
        if(lis+lds<7)
        {
            for(int i=0;i<9;++i)
                cout<<a[i];
            break;
        }
    }while(next_permutation(a,a+9));
}
 
int main() 
{ 
    //check();
    int n;
    cin>>n;
    if(n==1)
        cout<<"1";
    else 
    {
        int base=sqrt(n);
        int i=1;
        for(;i*base<=n;++i)
            for(int j=base*i,k=0;k<base;++k,--j)
                cout<<j<<" ";
        --i;
        while(n>i*base) cout<<n--<<" ";
    }
    return 0; 
} 

