//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXP 110
using namespace std;

int n;
bool refer[MAXP][MAXP];
int time[MAXP];
int a, k, b;
int maxtime, maxpos;

int main()
{
	memset(refer, false, sizeof(refer));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &k);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &b);
			refer[a][b] = true;
			time[b]++;
		}
	}
	for (int i = 1; i <= 100; i++)
		if (time[i] > maxtime)
		{
			maxtime = time[i];
			maxpos = i;
		}
	printf("%d\n", maxpos);
	for (int i = 1; i <= 100; i++)
		if (refer[i][maxpos])
			printf("%d ", i);
	return 0;
}
