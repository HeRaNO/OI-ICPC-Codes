#include <cstdio>
#include <algorithm>
#define MAXN 15010
using namespace std;

struct modify
{
	int type;
	long long a;
	long long b;
};

modify m[MAXN];
pair <long long, long long *> b[MAXN << 1];
long long x, y;
int n, T, opt, cnt, d;
int a[MAXN << 1];

bool cmp(int a, int b)
{
	return a > b;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'C')
		{
			x = 0;
			return ;
		}
		if (ch == 'D')
		{
			x = 1;
			return ;
		}
		if (ch == 'M')
		{
			x = 2;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
{
	x = 0LL;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("battle.in","r",stdin);freopen("battle.out","w",stdout);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(opt);
		if (!opt || opt == 1)
		{
			read(x);
			m[i] = (modify)
			{
				opt, x, 0LL
			};
			b[++cnt] = make_pair(m[i].a, &m[i].a);
		}
		else
		{
			read(x);
			read(y);
			m[i] = (modify)
			{
				opt, x, y
			};
			b[++cnt] = make_pair(m[i].a, &m[i].a);
			b[++cnt] = make_pair(m[i].b, &m[i].b);
		}
	}
	sort(b + 1, b + cnt + 1);
	for (int i = 1; i <= cnt; i++)
	{
		if (b[i].first != b[i - 1].first || i == 1) d++;
		*b[i].second = d;
	}
	for (int i = 1; i <= n; i++)
	{
		opt = m[i].type;
		x = m[i].a;
		y = m[i].b;
		if (!opt)
			a[x]++;
		else if (opt == 1)
		{
			if (a[x] > 0) a[x]--;
		}
		else
		{
			if (a[x] > 0 && a[y] > 0)
			{
				a[x] += a[y];
				a[y] = 0;
			}
		}
	}
	sort(a + 1, a + d + 1, cmp);
	read(T);
	while (T--)
	{
		read(opt);
		if (!a[opt] || opt > d) puts("NO");
		else printf("%d\n", a[opt]);
	}
	return 0;
}
