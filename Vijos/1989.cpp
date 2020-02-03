#include <cstdio>
#define MAXN 8010
using namespace std;
struct puzzle
{
	int x, y, r;
};
puzzle circle[MAXN];
int x1, x2, y1, y2;
int n, q;

int abs(int a)
{
	return a < 0 ? -a : a;
}

int get(int k, int x, int y)
{
	if (abs(x - circle[k].x) <= circle[k].r && abs(y - circle[k].y) <= circle[k].r)
		return 1;
	return 0;
}

int query(int x1, int y1, int x2, int y2)
{
	int i, ans = 0;
	for (i = 1; i <= n; i++)
		if (get(i, x1, y1) != get(i, x2, y2))
			ans++;
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &circle[i].x, &circle[i].y, &circle[i].r);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", query(x1, y1, x2, y2));
	}
	return 0;
}