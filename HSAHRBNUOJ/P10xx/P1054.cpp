#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct Server
{
	int p, w;
	Server() {}
	Server(int _p, int _w): p(_p), w(_w) {}
	bool operator < (const Server &a)const
	{
		return p < a.p;
	}
};

Server x[MAXN], y[MAXN];
int n, px, py, p, k, all, amt;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &px, &py, &p, &k);
		p *= k;
		all += p;
		p <<= 1;
		x[i] = Server(px, p);
		y[i] = Server(py, p);
	}
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; i++)
	{
		amt += x[i].w;
		if (amt >= all)
		{
			px = x[i].p;
			break;
		}
	}
	amt = 0;
	for (int i = 1; i <= n; i++)
	{
		amt += y[i].w;
		if (amt >= all)
		{
			py = y[i].p;
			break;
		}
	}
	printf("%d %d\n", px, py);
	return 0;
}