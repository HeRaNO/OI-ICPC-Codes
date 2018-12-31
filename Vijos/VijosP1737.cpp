#include <cstdio>
#define MAXK 51
using namespace std;

int color[MAXK], color_ok[MAXK];
long long ans;
int n, k, p;
int c, co;

int main()
{
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &c, &co);
		if (co <= p)
		{
			ans += color[c];
			color[c]++;
			for (int j = 0; j < k; j++) color_ok[j] = color[j];
		}
		else
		{
			ans += color_ok[c];
			color[c]++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}