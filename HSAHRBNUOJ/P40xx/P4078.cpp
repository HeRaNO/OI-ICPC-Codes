#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MAXB 320
using namespace std;

int n, m, c, T, RE, x, block, l, r;
int cnt[MAXN][MAXB], ans[MAXB][MAXB];
int pos[MAXN], a[MAXN], ap[MAXN], tim[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void Make_ans()
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= c; j++) cnt[j][i] = cnt[j][i - 1];
		int l = (i - 1) * block + 1, r = mymin(i * block, n);
		for (int j = l; j <= r; j++) cnt[a[j]][i]++;
	}
	for (int i = 1; i <= m; i++)
	{
		RE++;
		int l = (i - 1) * block + 1, amt = 0;
		for (int j = l; j <= n; j++)
		{
			if (tim[a[j]] != RE)
			{
				ap[a[j]] = 0;
				tim[a[j]] = RE;
			}
			if (++ap[a[j]] != 1) amt += (ap[a[j]] & 1) ? -1 : 1;
			if (pos[j] != pos[j + 1]) ans[i][pos[j]] = amt;
		}
	}
	return ;
}

inline int query(int l, int r)
{
	int res = 0, amt, L, R;
	RE++;
	if (pos[r] - pos[l] < 2)
	{
		for (int i = l; i <= r; i++)
		{
			if (tim[a[i]] != RE)
			{
				ap[a[i]] = 0;
				tim[a[i]] = RE;
			}
			if (++ap[a[i]] != 1) res += (ap[a[i]] & 1) ? -1 : 1;
		}
		return res;
	}
	if (pos[l] != pos[l - 1]) L = pos[l];
	else L = pos[l] + 1;
	if (pos[r] != pos[r + 1]) R = pos[r];
	else R = pos[r] - 1;
	res = ans[L][R];
	if (L != pos[l])
	{
		for (int i = l; i <= pos[l]*block; i++)
		{
			if (tim[a[i]] != RE)
			{
				ap[a[i]] = 0;
				tim[a[i]] = RE;
			}
			ap[a[i]] = cnt[a[i]][R] - cnt[a[i]][L - 1];
		}
	}
	if (R != pos[r])
	{
		for (int i = (pos[r] - 1) * block + 1; i <= r; i++)
		{
			if (tim[a[i]] != RE)
			{
				ap[a[i]] = 0;
				tim[a[i]] = RE;
			}
			ap[a[i]] = cnt[a[i]][R] - cnt[a[i]][L - 1];
		}
	}
	if (L != pos[l])
	{
		for (int i = l; i <= pos[l]*block; i++)
		{
			if (tim[a[i]] != RE)
			{
				ap[a[i]] = 0;
				tim[a[i]] = RE;
			}
			if (++ap[a[i]] != 1) res += (ap[a[i]] & 1) ? -1 : 1;
		}
	}
	if (R != pos[r])
	{
		for (int i = (pos[r] - 1) * block + 1; i <= r; i++)
		{
			if (tim[a[i]] != RE)
			{
				ap[a[i]] = 0;
				tim[a[i]] = RE;
			}
			if (++ap[a[i]] != 1) res += (ap[a[i]] & 1) ? -1 : 1;
		}
	}
	return res;
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
	//freopen("poetize.in","r",stdin);freopen("poetize.out","w",stdout);
	read(n);
	read(c);
	read(T);
	block = (int)sqrt(n);
	if (n % block) m = n / block + 1;
	else m = n / block;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block + 1;
	}
	Make_ans();
	while (T--)
	{
		read(l);
		read(r);
		l = (l + x) % n + 1;
		r = (r + x) % n + 1;
		if (l > r) swap(l, r);
		printf("%d\n", x = query(l, r));
	}
	return 0;
}