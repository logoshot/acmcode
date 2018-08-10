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
 
using namespace std;
 
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
	bool operator <(Int1000 b) const {
		if(len == b.len) {
			for(int i=len; i>=1; i--)
				if(a[i] < b.a[i]) return true;
				else if(a[i] > b.a[i]) return false;
			return false;
		}
		return len < b.len;
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
 
	Int1000 operator *(Int1000 b) {
		Int1000 ans;
		ans.len = len + b.len;
		for(int j=1; j<=b.len; j++) {
			for(int i=1; i<=len; i++) {
				ans.a[i+j-1] += b.a[j] * a[i];
				ans.a[i+j] += ans.a[i+j-1] / 10;
				ans.a[i+j-1] %= 10;
			}
			if(ans.a[b.len+len]) {
				ans.a[b.len+len+1] += ans.a[b.len+len] / 10;
				ans.a[b.len+len] %= 10;
			}
		}
		while(ans.len > 1 && !ans.a[ans.len]) ans.len --;
		return ans;
	}
	Int1000 operator /(const int &b) { //除以低精
		if(*this < Int1000(b)) return Int1000(0);
		Int1000 ans;
		ans.len = len;
		int r = 0;
		for(int i=ans.len; i>=1; i--) {
			r = r * 10 + a[i];
			ans.a[i] = r / b;
			r %= b;
		}
		while(ans.len > 1 && !ans.a[ans.len]) ans.len --;
		return ans;
	}
	Int1000 operator /(Int1000 b) {
		if(*this < b) return Int1000(0);
		Int1000 ans;
		ans.len = len - b.len + 1;
		for(int i=ans.len; i>=1; i--) {
			for(int j=1; j<=9; j++) {
				ans.a[i] ++;
				if((*this) < (ans * b)) {
					ans.a[i] --;
					break;
				}
			}
			if(ans.a[ans.len] == 0) ans.len --;
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
} A, B;
 
int main() {
	cout << "Input a, b (a > b):\n";
	A.Scan();
	B.Scan();
	cout << "A + B = ";
	(A+B).Print(1);
	cout << "A - B = ";
	(A-B).Print(1);
	cout << "A * B = ";
	(A*B).Print(1);
	cout << "A / B = ";
	(A/B).Print(1);
	return 0;
}

