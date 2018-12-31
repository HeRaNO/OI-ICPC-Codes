#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct city
{
	int p, y, pt;
	bool operator < (const city &a)const
	{
		return y < a.y;
	}
};

vector <city> a[MAXN], b;
int n, m, x, y;

bool cmp(city a, city b)
{
	return a.pt < b.pt;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		a[x].push_back((city)
		{
			x, y, i
		});
	}
	for (int i = 1; i <= n; i++)
	{
		if (!a[i].size()) continue;
		sort(a[i].begin(), a[i].end());
		for (int x = 0; x < a[i].size(); x++)
		{
			a[i][x].y = x + 1;
			b.push_back(a[i][x]);
		}
	}
	sort(b.begin(), b.end(), cmp);
	for (int i = 0; i < m; i++)
		printf("%06d%06d\n", b[i].p, b[i].y);
	return 0;
}