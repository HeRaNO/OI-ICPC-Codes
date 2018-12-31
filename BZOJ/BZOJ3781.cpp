#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 50010
#define MAXB 225
using namespace std;

struct query
{
	int l, r, id;
	long long res;
};

query ans[MAXN];
int n, T, k, block;
int a[MAXN], pos[MAXN];
long long cnt[MAXN], squ[MAXN], ANS;

bool cmp(query a, query b)
{
	return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}
bool cmp_id(query a, query b)
{
	return a.id < b.id;
}

inline void update(int x, int v)
{
	ANS -= squ[cnt[a[x]]];
	cnt[a[x]] += v;
	ANS += squ[cnt[a[x]]];
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
		ans[i].res = ANS;
	}
	sort(ans + 1, ans + T + 1, cmp_id);
	return ;
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
	read(T);
	read(k);
	block = (int)sqrt(n);
	for (long long i = 1; i <= n; i++) squ[i] = i * i;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block + 1;
	}
	for (int i = 1; i <= T; i++)
	{
		read(ans[i].l);
		read(ans[i].r);
		ans[i].id = i;
	}
	ModuiAlgorithm();
	for (int i = 1; i <= T; i++) printf("%lld\n", ans[i].res);
	return 0;
}
