#include <cmath>
#include <cstdio>
#define MAXN 400010
#define MAXM 635
#define MAXQ 25001
using namespace std;

inline void swap(int &x, int &y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	return ;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

int a[MAXN];

struct BigRootHeap
{
	int p[MAXM], tp;
	void push(int x)
	{
		p[++tp] = x;
		int t = tp;
		while (t > 1 && p[t] > p[t >> 1]) swap(p[t], p[t >> 1]), t >>= 1;
		return ;
	}
	int top()
	{
		return p[1];
	}
	void pop()
	{
		int t = 2;
		p[1] = p[tp];
		p[tp--] = 0;
		while (t <= tp)
		{
			if (p[t] < p[t + 1] && t < tp) ++t;
			if (p[t] > p[t >> 1]) swap(p[t], p[t >> 1]), t <<= 1;
			else break;
		}
		return ;
	}
	void Build(int l, int r)
	{
		tp = 0;
		for (int i = l; i <= r; i++) push(a[i]);
		return ;
	}
};

int c[MAXM][MAXQ];

struct SmallRootHeap
{
	int p[MAXQ], tp;
	void push(int x)
	{
		p[++tp] = x;
		int t = tp;
		while (t > 1 && p[t]<p[t >> 1]) swap(p[t], p[t >> 1]), t >>= 1;
		return ;
	}
	int top()
	{
		return p[1];
	}
	void pop()
	{
		int t = 2;
		p[1] = p[tp];
		p[tp--] = 0;
		while (t <= tp)
		{
			if (p[t] > p[t + 1] && t < tp) ++t;
			if (p[t]<p[t >> 1]) swap(p[t], p[t >> 1]), t <<= 1;
			else break;
		}
		return ;
	}
	void Build(int id)
	{
		tp = 0;
		int l = c[id][0];
		for (int i = 1; i <= l; i++) push(c[id][i]);
		c[id][0] = 0;
		return ;
	}
};

BigRootHeap x[MAXM];
SmallRootHeap y;
int n, T, m, l, r, A, pos[MAXN];

inline void Rebuild(int r)
{
	if (!c[r][0]) return ;
	y.Build(r);
	for (int i = r * m + 1, p = mymin((r + 1) * m, n), q; i <= p; i++)
	{
		q = y.top();
		if (a[i] > q)
		{
			y.pop();
			swap(q, a[i]);
			y.push(q);
		}
	}
	x[r].Build(r * m + 1, mymin((r + 1)*m, n));
	return ;
}

inline int work(int l, int r, int A)
{
	Rebuild(pos[l]);
	bool f;
	if (pos[l] == pos[r])
	{
		f = false;
		for (int i = l; i <= r; i++) if (a[i] > A) swap(a[i], A), f = true;
		if (f) x[pos[l]].Build(pos[l]*m + 1, mymin((pos[l] + 1)*m, n));
		return A;
	}
	Rebuild(pos[r]);
	f = false;
	for (int i = l, p = mymin((pos[l] + 1) * m, n); i <= p; i++) if (a[i] > A) swap(a[i], A), f = true;
	if (f) x[pos[l]].Build(pos[l]*m + 1, mymin((pos[l] + 1)*m, n));
	for (int i = pos[l] + 1, p = pos[r] - 1, q; i <= p; i++)
	{
		q = x[i].top();
		if (A >= q) continue;
		c[i][++c[i][0]] = A;
		x[i].pop();
		x[i].push(A);
		A = q;
	}
	f = false;
	for (int i = pos[r] * m + 1; i <= r; i++) if (a[i] > A) swap(a[i], A), f = true;
	if (f) x[pos[r]].Build(pos[r]*m + 1, mymin((pos[r] + 1)*m, n));
	return A;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	m = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / m;
		x[(i - 1) / m].push(a[i]);
	}
	while (T--)
	{
		read(l);
		read(r);
		read(A);
		printf("%d\n", l <= r ? work(l, r, A) : work(1, r, work(l, n, A)));
	}
	return 0;
}