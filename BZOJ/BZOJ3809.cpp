#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define MAXT 1000010
#define MAXB 320
using namespace std;

struct queryseq
{
	int l, r, a, b, id, res;
};

queryseq ans[MAXT];
int n, T, block_num;
int a[MAXN], pos[MAXN];
int sum[MAXB], cnt[MAXN];

bool cmp(queryseq a, queryseq b)
{
	return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}
bool cmp_id(queryseq a, queryseq b)
{
	return a.id < b.id;
}

inline int query(int l, int r)
{
	int res = 0;
	if (pos[l] == pos[r])
	{
		for (int i = l; i <= r; i++) res += (bool)cnt[i];
		return res;
	}
	for (int i = l; i <= pos[l]*block_num; i++) res += (bool)cnt[i];
	for (int i = (pos[r] - 1) * block_num + 1; i <= r; i++) res += (bool)cnt[i];
	for (int i = pos[l] + 1; i < pos[r]; i++) res += sum[i];
	return res;
}

inline void update(int x, int v)
{
	if (!~v)
	{
		cnt[a[x]]--;
		if (!cnt[a[x]]) sum[pos[a[x]]]--;
	}
	else
	{
		if (!cnt[a[x]]) sum[pos[a[x]]]++;
		cnt[a[x]]++;
	}
	return ;
}

inline void ModuiAlgorithm()
{
	sort(ans + 1, ans + T + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= T; i++)
	{
		while (r < ans[i].r) update(++r, 1);
		while (r > ans[i].r) update(r--, -1);
		while (l < ans[i].l) update(l++, -1);
		while (l > ans[i].l) update(--l, 1);
		ans[i].res = query(ans[i].a, ans[i].b);
	}
	sort(ans + 1, ans + T + 1, cmp_id);
	return ;
}

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

int main()
{
	read(n);
	read(T);
	block_num = (int)sqrt(n);
	for (int i = 1; i <= n; i++) read(a[i]), pos[i] = (i - 1) / block_num + 1;
	for (int i = 1; i <= T; i++) read(ans[i].l), read(ans[i].r), read(ans[i].a), read(ans[i].b), ans[i].id = i;
	ModuiAlgorithm();
	for (int i = 1; i <= T; i++) printf("%d\n", ans[i].res);
	return 0;
}
