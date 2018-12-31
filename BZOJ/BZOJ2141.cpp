#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 20010
#define MAXB 210
using namespace std;

int n, m, T, block, l, r, a[MAXN];
pair <int, int *> b[MAXN];
int pos[MAXN], cnt[MAXB][MAXN], ans;

inline int lowbit(int x)
{
	return x & -x;
}

inline void add(int c[], int x, int v)
{
	for (; x <= m; x += lowbit(x)) c[x] += v;
	return ;
}

inline int query(int c[], int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) res += c[x];
	return res;
}

inline int Solve_first()
{
	for (int i = n; i; i--)
	{
		ans += query(cnt[0], a[i] - 1);
		add(cnt[0], a[i], 1);
	}
	for (int i = 1; i <= n; i++) add(cnt[(i - 1) / block + 1], a[i], 1);
	return ans;
}

inline int query(int l, int r)
{
	if (pos[l] == pos[r])
	{
		for (int i = l + 1; i < r; i++) ans += (a[i] > a[l]) + (a[i] < a[r]) - (a[i] < a[l]) - (a[i] > a[r]);
		ans += (a[l] < a[r]) - (a[l] > a[r]);
		swap(a[l], a[r]);
		return ans;
	}
	for (int i = l + 1; i <= pos[l]*block; i++) ans += (a[i] > a[l]) + (a[i] < a[r]) - (a[i] < a[l]) - (a[i] > a[r]);
	for (int i = (pos[r] - 1) * block + 1; i < r; i++) ans += (a[i] > a[l]) + (a[i] < a[r]) - (a[i] < a[l]) - (a[i] > a[r]);
	for (int i = pos[l] + 1; i < pos[r]; i++)
	{
		ans -= query(cnt[i], a[l] - 1);
		ans += query(cnt[i], m) - query(cnt[i], a[l]);
		ans += query(cnt[i], a[r] - 1);
		ans -= query(cnt[i], m) - query(cnt[i], a[r]);
	}
	ans += (a[l] < a[r]) - (a[l] > a[r]);
	add(cnt[pos[l]], a[l], -1);
	add(cnt[pos[r]], a[r], -1);
	swap(a[l], a[r]);
	add(cnt[pos[l]], a[l], 1);
	add(cnt[pos[r]], a[r], 1);
	return ans;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	block = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block + 1;
		b[i] = make_pair(a[i], &a[i]);
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) m++;
		*b[i].second = m;
	}
	printf("%d\n", Solve_first());
	read(T);
	while (T--)
	{
		read(l);
		read(r);
		if (l > r) swap(l, r);
		printf("%d\n", query(l, r));
	}
	return 0;
}