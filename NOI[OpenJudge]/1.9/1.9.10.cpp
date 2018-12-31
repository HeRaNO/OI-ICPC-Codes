//Code By HeRaNO
#include <cstdio>
#define MAXR 32
#define MAXN 110
using namespace std;

int a[MAXR][MAXN];
int n;
int cnt[MAXR];
int ans[MAXR], anscnt;
int fmax;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int r = 1; r <= n; r++)
	{
		int i = 1;
		scanf("%d", &a[r][i]);
		fmax = mymax(fmax, a[r][i]);
		i++;
		while (scanf(",%d", &a[r][i]))
		{
			fmax = mymax(fmax, a[r][i]);
			i++;
		}
		cnt[r] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= cnt[i]; j++)
			if (a[i][j] == fmax)
			{
				ans[++anscnt] = i;
				break;
			}
	}
	printf("%d\n", fmax);
	for (int i = 1; i < anscnt; i++) printf("%d,", ans[i]);
	printf("%d\n", ans[anscnt]);
	return 0;
}
