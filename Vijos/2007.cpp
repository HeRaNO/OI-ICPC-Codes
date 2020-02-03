#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define MAXM 7000010
using namespace std;

struct Monotonous_Queue
{
	int q[MAXN + MAXM], head, tail;
	Monotonous_Queue(): head(1), tail(0) {}
	__attribute__((__optimize__("-O2"))) void push(int x)
	{
		q[++tail] = x;
		return ;
	}
	__attribute__((__optimize__("-O2"))) void pop()
	{
		head++;
		return ;
	}
	__attribute__((__optimize__("-O2"))) int front()
	{
		return q[head];
	}
	__attribute__((__optimize__("-O2"))) bool empty()
	{
		return head > tail;
	}
};

Monotonous_Queue Q[3];
int n, m, q, u, v, t, x, y, delta;
long long new1, new2;
int a[MAXN];
bool first = true;

__attribute__((__optimize__("-O2"))) inline int GetMax()
{
	int res = -1;
	for (int i = 0; i < 3; i++)
	{
		if (Q[i].empty()) continue;
		if (!~res || Q[i].front() > Q[res].front()) res = i;
	}
	return res;
}

__attribute__((__optimize__("-O2"))) inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

__attribute__((__optimize__("-O2"))) int main()
{
	read(n);
	read(m);
	read(q);
	read(u);
	read(v);
	read(t);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = n; i; i--) Q[0].push(a[i]);
	for (int i = 1; i <= m; i++)
	{
		x = GetMax();
		y = Q[x].front();
		Q[x].pop();
		y += delta;
		if (!(i % t))
		{
			if (first)
			{
				printf("%d", y);
				first = false;
			}
			else printf(" %d", y);
		}
		delta += q;
		new1 = (long long)y * u / v;
		new2 = y - new1;
		new1 -= delta;
		new2 -= delta;
		Q[1].push(new1);
		Q[2].push(new2);
	}
	puts("");
	first = true;
	for (int i = 1; i <= n + m; i++)
	{
		x = GetMax();
		y = Q[x].front();
		Q[x].pop();
		if (!(i % t))
		{
			if (first)
			{
				printf("%d", y + delta);
				first = false;
			}
			else printf(" %d", y + delta);
		}
	}
	puts("");
	return 0;
}
