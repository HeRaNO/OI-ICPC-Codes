#include <cstdio>
#include <algorithm>
using namespace std;

int dis[40];
int f[40];
int a, b, n, i, j;

int main()
{
	//freopen("j5.in","r",stdin);
	//freopen("j5.out","w",stdout);
	dis[1] = 0;
	dis[2] = 990;
	dis[3] = 1010;
	dis[4] = 1970;
	dis[5] = 2030;
	dis[6] = 2940;
	dis[7] = 3060;
	dis[8] = 3930;
	dis[9] = 4060;
	dis[10] = 4970;
	dis[11] = 5030;
	dis[12] = 5990;
	dis[13] = 7000;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &n);
	n += 13;
	for (i = 14; i <= n; i++)
		scanf("%d", &dis[i]);
	sort(dis + 1, dis + n + 1);
	f[1] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j < i; j++)
		{
			if (dis[i] - dis[j] >= a && dis[i] - dis[j] <= b)
				f[i] += f[j];
		}
	printf("%d\n", f[n]);
	return 0;
}
