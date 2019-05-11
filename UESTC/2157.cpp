#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 40010
#define MAXB 210
using namespace std;

int n, m, T, block, x, c, a[MAXN], l, r;
int cnt[MAXN][MAXB], ans[MAXB][MAXB];
int pos[MAXN], ori[MAXN], ap[MAXN];
pair <int, int *> b[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void Discretization()
{
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || b[i].first != b[i - 1].first) ori[++c] = b[i].first;
		*b[i].second = c;
	}
	return ;
}

inline void Makeans()
{
	for (int i = 1; i <= m; i++)
	{
		int l = (i - 1) * block + 1, r = mymin(i * block, n);
		for (int j = l; j <= r; j++) cnt[a[j]][i]++;
	}
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= m; j++)
			cnt[i][j] += cnt[i][j - 1];
	for (int i = 1; i <= m; i++)
	{
		memset(ap, 0, sizeof ap);
		int l = (i - 1) * block + 1, mx = 0, pt = 0;
		for (int j = l; j <= n; j++)
		{
			ap[a[j]]++;
			if (ap[a[j]] > mx)
			{
				mx = ap[a[j]];
				pt = a[j];
			}
			else if (ap[a[j]] == mx && pt > a[j]) pt = a[j];
			if (pos[j] != pos[j + 1]) ans[i][pos[j]] = pt;
		}
	}
	return ;
}

inline int query(int l, int r)
{
	int mx = 0, pt = 0, L, R;
	memset(ap, 0, sizeof ap);
	if (pos[r] - pos[l] < 2)
	{
		for (int i = l; i <= r; i++)
		{
			ap[a[i]]++;
			if (ap[a[i]] > mx)
			{
				mx = ap[a[i]];
				pt = a[i];
			}
			else if (ap[a[i]] == mx && pt > a[i]) pt = a[i];
		}
		return ori[pt];
	}
	if (pos[l] != pos[l - 1]) L = pos[l];
	else L = pos[l] + 1;
	if (pos[r] != pos[r + 1]) R = pos[r];
	else R = pos[r] - 1;
	pt = ans[L][R];
	mx = cnt[pt][R] - cnt[pt][L - 1];
	if (L != pos[l]) for (int i = l; i <= pos[l]*block; i++) ap[a[i]]++;
	if (R != pos[r]) for (int i = (pos[r] - 1) * block + 1; i <= r; i++) ap[a[i]]++;
	for (int i = l; i <= pos[l]*block; i++)
		if (ap[a[i]])
		{
			if (ap[a[i]] + (cnt[a[i]][R] - cnt[a[i]][L - 1]) > mx)
			{
				mx = ap[a[i]] + (cnt[a[i]][R] - cnt[a[i]][L - 1]);
				pt = a[i];
			}
			else if (ap[a[i]] + (cnt[a[i]][R] - cnt[a[i]][L - 1]) == mx && pt > a[i]) pt = a[i];
			ap[a[i]] = 0;
		}
	for (int i = (pos[r] - 1) * block + 1; i <= r; i++)
		if (ap[a[i]])
		{
			if (ap[a[i]] + (cnt[a[i]][R] - cnt[a[i]][L - 1]) > mx)
			{
				mx = ap[a[i]] + (cnt[a[i]][R] - cnt[a[i]][L - 1]);
				pt = a[i];
			}
			else if (ap[a[i]] + (cnt[a[i]][R] - cnt[a[i]][L - 1]) == mx && pt > a[i]) pt = a[i];
			ap[a[i]] = 0;
		}
	return ori[pt];
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
	//freopen("dandelion.in","r",stdin);freopen("dandelion.out","w",stdout);
	read(n);
	read(T);
	block = (int)sqrt(n);
	if (n % block) m = n / block + 1;
	else m = n / block;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		b[i] = make_pair(a[i], &a[i]);
		pos[i] = (i - 1) / block + 1;
	}
	Discretization();
	Makeans();
	while (T--)
	{
		read(l);
		read(r);
		l = (l + x - 1) % n + 1;
		r = (r + x - 1) % n + 1;
		if (l > r) swap(l, r);
		printf("%d\n", x = query(l, r));
	}
	return 0;
}
