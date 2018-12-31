#include <cstdio>
#define MAXN 10010
using namespace std;

struct square
{
	int x1;
	int y1;
	int xlen;
	int ylen;
};

struct point
{
	int x;
	int y;
};

square a[MAXN];
point ask;
int ans;
int n;

int main()
{
	//freopen("carpet.in","r",stdin);freopen("carpet.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].xlen, &a[i].ylen);
	scanf("%d %d", &ask.x, &ask.y);
	for (int i = 1; i <= n; i++)
	{
		if (ask.x >= a[i].x1 && ask.x <= a[i].x1 + a[i].xlen)
			if (ask.y >= a[i].y1 && ask.y <= a[i].y1 + a[i].ylen)
				ans = i;
	}
	printf("%d\n", ans ? ans : -1);
	return 0;
}
