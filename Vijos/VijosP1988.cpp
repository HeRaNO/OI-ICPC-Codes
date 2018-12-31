#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300001;
int n, ans, worst, now;
int b[MAXN];

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	sort(b + 1, b + 1 + n);
	now = n;
	for (i = 1; i <= n; i++)
	{
		worst = max(worst, b[i] + now);
		now--;
	}
	worst -= n;
	for (i = 1; i <= n; i++)
		if (b[i] >= worst)
			ans++;
	printf("%d", ans);
	return 0;
}