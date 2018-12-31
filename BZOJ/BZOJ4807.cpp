#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

int n, m, t;
int prime[MAXN], d[MAXN], cnt[MAXN], tot;
bool not_prime[MAXN];

struct longint
{
	int s[55];
	longint()
	{
		memset(s, 0, sizeof s);
	}
	longint operator * (const int &a)const
	{
		longint c;
		for (int i = 1; i <= 50; i++)
		{
			c.s[i] += s[i] * a;
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		return c;
	}
	void print()
	{
		int a = 50;
		while (!s[a] && a) a--;
		for (int i = a; i; i--) putchar(s[i] + '0');
		putchar('\n');
		return ;
	}
} ans;

inline void Linear_Shaker()
{
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i]) prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			d[i * prime[j]] = prime[j];
			if (!(i % prime[j])) break;
		}
	}
	return ;
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n < m)
	{
		t = n;
		n = m;
		m = t;
	}
	Linear_Shaker();
	for (int i = m + 1; i <= n; i++) cnt[i] = 1;
	for (int i = 2; i <= n - m; i++) --cnt[i];
	for (int i = n; i >= 2; i--)
		if (not_prime[i]) cnt[d[i]] += cnt[i], cnt[i / d[i]] += cnt[i], cnt[i] = 0;
	ans.s[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= cnt[i]; j++)
			ans = ans * i;
	ans.print();
	return 0;
}