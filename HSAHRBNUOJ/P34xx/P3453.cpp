#include <queue>
#include <cstdio>
#define MAXN 100010
#define MOD 1000000007LL
using namespace std;

int n;
long long a[MAXN], ans;
priority_queue <pair<long long, int> > q;

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

inline void read(long long &x)
{
	x = 0LL;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	//freopen("orz.in","r",stdin);freopen("orz.out","w",stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	a[n + 1] = 1;
	for (int i = 1; i <= n; i++) ans = (ans - a[i] + MOD) % MOD;
	q.push(make_pair(a[1], 1));
	for (int i = 2; i <= n + 1; i++)
	{
		while (q.top().first >= a[i])
		{
			pair <long long, int> u = q.top();
			q.pop();
			ans = (ans + u.first * (i - u.second)) % MOD;
			q.push(make_pair(u.first % a[i], i));
		}
		q.push(make_pair(a[i], i));
	}
	printf("%lld\n", ans);
	return 0;
}
