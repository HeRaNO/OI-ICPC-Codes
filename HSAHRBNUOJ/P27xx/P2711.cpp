#include <cstdio>
#define MAXN 110
using namespace std;

struct point
{
	int x;
	int y;
};

point a[MAXN];
int n, ans;

bool judge(int p, int q, int r)
{
	if (a[p].x == a[q].x && a[q].x == a[r].x) return false;
	if (a[p].y == a[q].y && a[q].y == a[r].y) return false;
	if ((a[r].y - a[q].y) * (a[q].x - a[p].x) == (a[r].x - a[q].x) * (a[q].y - a[p].y)) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].x, &a[i].y);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
				if (judge(i, j, k)) ans++;
	printf("%d\n", ans);
	return 0;
}
