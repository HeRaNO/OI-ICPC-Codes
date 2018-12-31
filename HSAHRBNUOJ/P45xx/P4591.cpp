#include <cstdio>
#include <vector>
#define MAXN 300010
using namespace std;

char ib[20000007], *ip = ib;
inline void read(int &x)
{
	x = 0;
	while (*ip < '0' || *ip > '9') ++ip;
	while (*ip >= '0' && *ip <= '9') x = x * 10 + *ip++ -'0';
	return ;
}

int rt[MAXN], lc[MAXN * 30], rc[MAXN * 30], siz[MAXN * 30], top;
int n, m, T, R, x, y, c;
long long a;
vector <long long> last[MAXN];

inline int query(int u, int l, int r, int x)
{
	if (l + 1 == r) return l;
	int mid = l + r >> 1;
	int szl = mid - l - siz[lc[u]];
	if (x <= szl) query(lc[u], l, mid, x);
	else query(rc[u], mid, r, x - szl);
}

inline void del(int &u, int l, int r, int x)
{
	if (!u) u = ++top;
	siz[u]++;
	if (l + 1 == r) return ;
	int mid = l + r >> 1;
	if (x < mid) del(lc[u], l, mid, x);
	else del(rc[u], mid, r, x);
}

int main()
{
	//freopen("phalanx.in","r",stdin);freopen("phalanx.out","w",stdout);
	fread(ib, 1, sizeof ib, stdin);
	read(n);
	read(m);
	read(T);
	R = n > m ? n : m;
	R += T + 1;
	while (T--)
	{
		read(x);
		read(y);
		if (y == m)
		{
			c = query(rt[n + 1], 1, R, x);
			del(rt[n + 1], 1, R, c);
			a = 1LL * c * m;
			if (c > n) a = last[n + 1][c - n - 1];
			last[n + 1].push_back(a);
			printf("%lld\n", a);
		}
		else
		{
			c = query(rt[x], 1, R, y);
			del(rt[x], 1, R, c);
			a = 1LL * (x - 1) * m + c;
			if (c >= m) a = last[x][c - m];
			last[n + 1].push_back(a);
			printf("%lld\n", a);
			c = query(rt[n + 1], 1, R, x);
			del(rt[n + 1], 1, R, c);
			a = 1LL * c * m;
			if (c > n) a = last[n + 1][c - n - 1];
			last[x].push_back(a);
		}
	}
	//puts("Goodbye OI!");Goodbye 30pts!Goodbye 1=!
	return 0;
}