#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct hose
{
	int l, r, id;
	long long ansa, ansb;
};

hose res[MAXN];
int n, T, block_num;
int pos[MAXN], color[MAXN];
long long a[MAXN], ans;

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

bool cmp(hose a, hose b)
{
	if (pos[a.l] == pos[b.l]) return a.r < b.r;
	return a.l < b.l;
}

bool cmp_id(hose a, hose b)
{
	return a.id < b.id;
}
long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

void update(int x, int add)
{
	ans -= a[color[x]] * a[color[x]];
	a[color[x]] += add;
	ans += a[color[x]] * a[color[x]];
}

inline void ModuiFun()
{
	sort(res + 1, res + T + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= T; i++)
	{
		while (r < res[i].r) update(r + 1, 1), r++;
		while (r > res[i].r) update(r, -1), r--;
		while (l < res[i].l) update(l, -1), l++;
		while (l > res[i].l) update(l - 1, 1), l--;
		if (res[i].l == res[i].r)
		{
			res[i].ansa = 0LL;
			res[i].ansb = 1LL;
			continue;
		}
		res[i].ansa = ans - (res[i].r - res[i].l + 1);
		res[i].ansb = (long long)(res[i].r - res[i].l + 1) * (res[i].r - res[i].l);
		long long k = gcd(res[i].ansa, res[i].ansb);
		res[i].ansa /= k;
		res[i].ansb /= k;
	}
	sort(res + 1, res + T + 1, cmp_id);
	return ;
}

int main()
{
	n = read();
	T = read();
	block_num = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		color[i] = read();
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; i <= T; i++)
	{
		res[i].l = read();
		res[i].r = read();
		res[i].id = i;
	}
	ModuiFun();
	for (int i = 1; i <= T; i++) printf("%lld/%lld\n", res[i].ansa, res[i].ansb);
	return 0;
}
