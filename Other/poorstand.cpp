#include <cmath>
#include <cstdio>
#define MAXB 1010
#define MAXN 1000010
using namespace std;

int n, T, m, block_num;
int l, r;
long long d;
int pos[MAXN];
long long a[MAXN], sum[MAXB];
long long add_lazy[MAXB], phi_lazy[MAXB];
char opt[5];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
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

inline void read(long long &x)
{
	x = 0LL;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	x *= f;
	return ;
}

inline void clean(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) sum[x] += a[i];
	return ;
}

inline void apply_add(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) a[i] += add_lazy[x];
	add_lazy[x] = 0LL;
	return ;
}

inline void apply_phi(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) a[i] += phi_lazy[x] * i;
	phi_lazy[x] = 0LL;
	return ;
}

inline void Apply(int x)
{
	if (add_lazy[x]) apply_add(x);
	if (phi_lazy[x]) apply_phi(x);
	return ;
}

inline void add(int left, int right, long long q)
{
	if (pos[left] == pos[right])
	{
		Apply(pos[left]);
		for (int i = left; i <= right; i++) a[i] += q;
		sum[pos[left]] += (right - left + 1) * q;
		return ;
	}
	Apply(pos[left]);
	Apply(pos[right]);
	for (int i = left; i <= pos[left]*block_num; i++) a[i] += q, sum[pos[left]] += q;
	for (int i = (pos[right] - 1) * block_num + 1; i <= right; i++) a[i] += q, sum[pos[right]] += q;
	for (int i = pos[left] + 1; i < pos[right]; i++)
	{
		add_lazy[i] += q;
		int l = (i - 1) * block_num + 1, r = mymin(i * block_num, n);
		sum[i] += (r - l + 1) * q;
	}
	return ;
}

inline void phi(int left, int right, long long d)
{
	if (pos[left] == pos[right])
	{
		Apply(pos[left]);
		for (int i = left; i <= right; i++)
		{
			a[i] += i * d;
			sum[pos[left]] += i * d;
		}
		return ;
	}
	Apply(pos[left]);
	Apply(pos[right]);
	for (int i = left; i <= pos[left]*block_num; i++)
	{
		a[i] += i * d;
		sum[pos[left]] += i * d;
	}
	for (int i = (pos[right] - 1) * block_num + 1; i <= right; i++)
	{
		a[i] += i * d;
		sum[pos[right]] += i * d;
	}
	for (int i = pos[left] + 1; i < pos[right]; i++)
	{
		phi_lazy[i] += d;
		int l = (i - 1) * block_num + 1, r = mymin(i * block_num, n);
		sum[i] += ((d * (r - l + 1) * (l + r)) >> 1LL);
	}
	return ;
}

inline long long query(int left, int right)
{
	long long res = 0LL;
	if (pos[left] == pos[right])
	{
		Apply(pos[left]);
		for (int i = left; i <= right; i++) res += a[i];
		return res;
	}
	Apply(pos[left]);
	Apply(pos[right]);
	for (int i = left; i <= pos[left]*block_num; i++) res += a[i];
	for (int i = (pos[right] - 1) * block_num + 1; i <= right; i++) res += a[i];
	for (int i = pos[left] + 1; i < pos[right]; i++) res += sum[i];
	return res;
}

int main()
{
	//freopen("poorstand.in","r",stdin);freopen("poorstand.out","w",stdout);
	read(n);
	read(T);
	block_num = (int)sqrt(n);
	m = n / block_num;
	if (n % block_num) m++;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; i <= m; i++) clean(i);
	while (T--)
	{
		scanf("%s", opt);
		if (opt[0] == 'A')
		{
			read(l);
			read(r);
			read(d);
			add(l, r, d);
		}
		else if (opt[0] == 'Q')
		{
			read(l);
			read(r);
			printf("%lld\n", query(l, r));
		}
		else
		{
			read(l);
			read(r);
			read(d);
			phi(l, r, d);
		}
	}
	return 0;
}
