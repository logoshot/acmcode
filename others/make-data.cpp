#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream ou("data.txt",ios::out);
    int t=100;
    ou<<t<<endl;
    for(int i=0;i<100;++i)
    {
        int n=rand()%20+1;
        ou<<n<<" ";
        for(int j=0;j<n;++j)
            ou<<rand()%10;
        ou<<endl;
    }
    return 0;
}
