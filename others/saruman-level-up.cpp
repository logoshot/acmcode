#include<string>
#include<vector>
#include<math.h>
#include<map>
#include <iostream>
#include <utility>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

long long c(long long a, long long b)
{
	if (a == b || b == 0) return 1;
	long long ans = 1, t = 2;
	for (int i = 0; i < b; ++i)
	{
		ans *= a--;
		while (t <= b && ans % t == 0) {
			ans /= t;
			t++;
		}
	}
	while (t <= b) ans /= t++;
	return ans;
}
int main()
{
	long long n;
	while (cin >> n)
	{
		long long mmmm = n;
		int data[100];
		int cnt = 0;
		while (n)
		{
			int temp = n % 2;
			data[cnt++] = temp;
			n >>= 1;
		}
		long long ans = 0;
		int pre = 0;
		for (int i = cnt - 1; i >= 0; i--)
		{
			if (data[i] == 1)
			{
				for (int j = 3; j <= 100; j += 3)
				{
					if (j - pre < 0)
					{
						continue;
					}
					if (j - pre > i)
					{
						break;
					}
					ans += c(i, j - pre);
				}
				pre++;
			}
		}
		if (pre % 3 == 0) ans++;
		cout << "Day " << mmmm << ": Level = " << ans << endl;
	}
	return 0;
}
