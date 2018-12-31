#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

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

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

pair <int, int *> b[MAXN];
int a[MAXN], ori[MAXN];
int n, m, k, tail;
int cnt[MAXN];
int ans, tot;

int main()
{
	read(n);
	read(k);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		b[i].first = a[i];
		b[i].second = &a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) ori[++m] = b[i].first;
		*b[i].second = m;
	}
	for (int i = 1; i <= n; i++)
	{
		while (tot <= k && tail < n)
		{
			cnt[a[++tail]]++;
			if (a[i] != a[tail] && cnt[a[tail]] == 1) tot++;
		}
		ans = mymax(ans, cnt[a[i]]);
		cnt[a[i]]--;
		if (!cnt[a[i]]) tot--;
	}
	printf("%d\n", ans);
	return 0;
}
