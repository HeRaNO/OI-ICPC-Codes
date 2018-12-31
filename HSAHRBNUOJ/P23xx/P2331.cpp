#include <cstdio>
using namespace std;

int bad, good;
int n, t, flag, ans;
int i, j;

int main()
{
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		bad = good = 0;
		ans = 0;
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &flag);
			if (flag == 1) good++;
			else bad++;
		}
		ans = good - bad;
		if (ans < 0) printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}
