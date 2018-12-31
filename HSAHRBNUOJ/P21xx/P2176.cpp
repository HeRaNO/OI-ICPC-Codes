#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 50010
#define MAXT 200010
#define MAXS 1000010
using namespace std;

struct necklace
{
	int l, r, ans, id;
};

necklace res[MAXT];
int n, T, l = 1, r, k, block_num;
int a[MAXN], pos[MAXN];
int cnt[MAXS];

bool cmp(necklace a, necklace b)
{
	return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}
bool cmp_id(necklace a, necklace b)
{
	return a.id < b.id;
}

inline void update(int pos, int v)
{
	if (!~v)
	{
		cnt[a[pos]]--;
		if (!cnt[a[pos]]) k--;
	}
	else
	{
		if (!cnt[a[pos]]) k++;
		cnt[a[pos]]++;
	}
	return ;
}

inline void ModuiAlgorithm()
{
	sort(res + 1, res + T + 1, cmp);
	for (int i = 1; i <= T; i++)
	{
		while (r < res[i].r) update(++r, 1);
		while (r > res[i].r) update(r--, -1);
		while (l < res[i].l) update(l++, -1);
		while (l > res[i].l) update(--l, 1);
		res[i].ans = k;
	}
	sort(res + 1, res + T + 1, cmp_id);
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
	//freopen("diff.in","r",stdin);freopen("diff.out","w",stdout);
	read(n);
	block_num = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block_num + 1;
	}
	read(T);
	for (int i = 1; i <= T; i++)
	{
		read(res[i].l);
		read(res[i].r);
		res[i].id = i;
	}
	ModuiAlgorithm();
	for (int i = 1; i <= T; i++) printf("%d\n", res[i].ans);
	return 0;
}
