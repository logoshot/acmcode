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
#define ex 1e-2
 
using namespace std; 
 
const int M = 1000*1000+10; 
int up=1000;

struct Int1000 {
	int a[1001], len;
	bool minus;
	Int1000(int x = 0) { //x非负
		for(int i=0; i<1001; i++) a[i] = 0;
		len = 0;
		do {
			a[++len] = x % 10;
			x /= 10;
		} while(x);
		minus = 0;
	}
    Int1000 operator =(Int1000 b)
    {
        this->len=b.len;
        for(int i=0;i<=b.len;++i)
            this->a[i]=b.a[i];
        return b;
    }
	Int1000 operator -(Int1000 b) {
		if(*this < b) {
			Int1000 ans = b - (*this);
			ans.minus = 1;
			return ans;
		}
		Int1000 ans;
		ans.len = max(len, b.len);
		for(int i=1; i<=ans.len; i++) {
			if(a[i] < b.a[i]) {
				a[i+1] --;
				a[i] += 10;
			}
			ans.a[i] += a[i] - b.a[i];
		}
		while(ans.len > 1 && !ans.a[ans.len]) ans.len --;
		return ans;
	}
	bool operator <(Int1000 b) const {
		if(len == b.len) {
			for(int i=len; i>=1; i--)
				if(a[i] < b.a[i]) return true;
				else if(a[i] > b.a[i]) return false;
			return false;
		}
		return len < b.len;
	}
    bool operator ==(Int1000 b) const {
        if(len!=b.len) return false;
        for(int i=len;i>=1;--i)
            if(a[i]!=b.a[i]) return false;
        return true;
    }
	Int1000 operator +(Int1000 b) {
		Int1000 ans;
		ans.len = max(len, b.len) + 1;
		for(int i=1; i<=ans.len; i++) {
			ans.a[i] += a[i] + b.a[i];
			ans.a[i+1] = ans.a[i] / 10;
			ans.a[i] %= 10;
		}
		while(ans.len > 1 && !ans.a[ans.len]) ans.len --;
		return ans;
	}
	void Scan() {
		char s[1001];
		cin >> s;
		len = strlen(s);
		for(int i=0; i<len; i++) a[len-i] = s[i] - '0';
	}
	void Print(bool h) const {
		if(minus) cout << '-';
		for(int i=len; i>=1; i--)
			cout << a[i];
		if(h) cout << endl;
	}
} fib[2000];


void init()
{
    fib[1].len=fib[2].len=1,fib[1].a[1]=1,fib[2].a[1]=2;
    for(int i=3;i<=up;++i)
        fib[i]=fib[i-1]+fib[i-2];
}

int get(Int1000 x)
{
    if(x.len==0||x.minus) return 0;
    int lo=0,hi=up;
    int mid=(lo+hi)>>1;
    while(lo<hi)
    {
        if(fib[mid]==x) return mid;
        if(fib[mid]<x) lo=mid+1;
        else hi=mid-1;
        mid=(lo+hi)>>1;
    }
    if(x<fib[lo]) --lo;
    return lo;
}
 
int main() 
{ 
    init();
    //for(int i=1;i<100;++i) fib[i].Print(1);
    Int1000 a,b;
    Int1000 c;
    Int1000 d(1);
    while(1)
    {
        a.Scan();b.Scan();
        if(a==c&&b==c) break;
        cout<<get(b)-get(a-d)<<endl;
    }
    return 0; 
} 

