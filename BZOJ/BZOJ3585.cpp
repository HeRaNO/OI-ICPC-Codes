#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 200010
#define MAXB 450
using namespace std;

struct mex
{
	int l, r, id, ans;
};

mex res[MAXN];
int n, m, T, block_num;
int pos[MAXN], a[MAXN];
int sum[MAXB], c[MAXN];

bool cmp(mex a, mex b)
{
	return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}
bool cmp_id(mex a, mex b)
{
	return a.id < b.id;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void update(int x, int v)
{
	if (a[x] > n) return ;
	int p = a[x];
	if (!c[p] && v == 1)  sum[pos[p]]++;
	if (c[p] == 1 && !~v) sum[pos[p]]--;
	c[p] += v;
	return ;
}

inline int Query()
{
	if (!c[0]) return 0;
	int i;
	for (i = 1; i <= m; i++)
	{
		int l = (i - 1) * block_num + 1, r = mymin(i * block_num, n);
		if (sum[i] != r - l + 1)
		{
			for (int j = l; j <= r; j++) if (!c[j]) return j;
		}
	}
	return n;
}

inline void ModuiAlgorithm()
{
	sort(res + 1, res + T + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= T; i++)
	{
		while (r < res[i].r) update(++r, 1);
		while (r > res[i].r) update(r--, -1);
		while (l < res[i].l) update(l++, -1);
		while (l > res[i].l) update(--l, 1);
		res[i].ans = Query();
	}
	sort(res + 1, res + T + 1, cmp_id);
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
	if (n % block_num) m = n / block_num + 1;
	else m = n / block_num;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block_num + 1;
	}
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
