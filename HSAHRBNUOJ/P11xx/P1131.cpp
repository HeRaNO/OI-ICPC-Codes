#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long ans, x, y;
priority_queue<long long, vector<long long>, greater<long long> > q;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(x), q.push(x);
	while (--n)
	{
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		ans += (x + y);
		q.push(x + y);
	}
	printf("%lld\n", ans);
	return 0;
}