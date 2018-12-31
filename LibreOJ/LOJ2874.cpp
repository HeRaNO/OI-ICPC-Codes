#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXB 350
#define MAXN 100010
using namespace std;

pair <int, int *> a[MAXN];
int n, m, T, block_num;
int b[MAXN], pos[MAXN];
int L[MAXB], R[MAXB], ori[MAXN];
int tim[MAXN];
int cnt[MAXB][MAXN], cnt1[MAXN];
long long mx[MAXB][MAXB], ans;
int l, r;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

long long query(int left, int right)
{
	long long res = mx[pos[left] + 1][pos[right] - 1];
	if (pos[left] == pos[right])
	{
		for (int i = left; i <= right; i++)
		{
			if (tim[b[i]] != T) tim[b[i]] = T, cnt1[b[i]] = 0;
			res = mymax(res, (long long)ori[b[i]] * (++cnt1[b[i]]));
		}
		return res;
	}
	for (int i = left; i <= R[pos[left]]; i++)
	{
		if (tim[b[i]] != T) tim[b[i]] = T, cnt1[b[i]] = cnt[pos[right] - 1][b[i]] - cnt[pos[left]][b[i]];
		res = mymax(res, (long long)ori[b[i]] * (++cnt1[b[i]]));
	}
	for (int i = L[pos[right]]; i <= right; i++)
	{
		if (tim[b[i]] != T) tim[b[i]] = T, cnt1[b[i]] = cnt[pos[right] - 1][b[i]] - cnt[pos[left]][b[i]];
		res = mymax(res, (long long)ori[b[i]] * (++cnt1[b[i]]));
	}
	return res;
}

int main()
{
	n = read();
	T = read();
	block_num = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		a[i].first = read();
		a[i].second = &b[i];
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; (i - 1)*block_num + 1 <= n; i++)
		L[i] = (i - 1) * block_num + 1, R[i] = mymin(i * block_num, n);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || a[i].first != a[i - 1].first) ori[++m] = a[i].first;
		*a[i].second = m;
	}
	for (int i = 1; i <= n; i++) cnt[pos[i]][b[i]]++;
	for (int i = 1; L[i]; i++)
		for (int j = 1; j <= n; j++)
			cnt[i][j] += cnt[i - 1][j];
	for (int i = 1; L[i]; i++)
	{
		ans = 0LL;
		memset(cnt1, 0, sizeof cnt1);
		for (int j = L[i]; j <= n; j++)
		{
			ans = mymax(ans, (long long)(++cnt1[b[j]]) * ori[b[j]]);
			if (j == R[pos[j]]) mx[i][pos[j]] = ans;
		}
	}
	memset(cnt1, 0, sizeof cnt1);
	while (T--)
	{
		l = read();
		r = read();
		printf("%lld\n", query(l, r));
	}
	return 0;
}