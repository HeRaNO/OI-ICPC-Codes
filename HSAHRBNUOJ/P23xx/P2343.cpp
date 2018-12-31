#include <cstdio>
#include <algorithm>
#define MAXN 110
#define MAXK 1100
using namespace std;

struct fall
{
	int y;
	int x1;
	int x2;
};

fall a[MAXN];
int x, y, ans;
int n, ypos, pos;

bool cmp(fall a, fall b)
{
	if (a.y == b.y) return a.x1 < b.x1;
	return a.y < b.y;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &x, &y);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &a[i].y, &a[i].x1, &a[i].x2);
	a[0].y = 0;
	a[0].x1 = -1, a[0].x2 = -1;
	sort(a, a + n + 1, cmp);
	for (int i = n; i; i--)
		if (a[i].y <= y)
		{
			pos = i;
			break;
		}
	for (int i = pos; i; i--)
	{
		if (a[i].x1 <= x && x <= a[i].x2)
		{
			ans = ans + y - a[i].y + 5;
			x = a[i].x2;
			y = a[i].y;
		}
	}
	printf("%d\n", ans + y);
	return 0;
}