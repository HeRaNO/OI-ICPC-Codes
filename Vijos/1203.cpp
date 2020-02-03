#include <cstdio>
#define MAXN 1001
using namespace std;

int n, f, k;
int tmp, need;
int ans, remain;
int foot[MAXN];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%d", &f);
	for (int i = 1; i <= f; i++)
	{
		scanf("%d %d", &tmp, &need);
		foot[tmp] += need;
	}
	for (int i = 1; i <= n; i++)
	{
		need = foot[i] + 1;
		if (remain < need)
		{
			ans++;
			remain = k;
		}
		remain -= need;
	}
	printf("%d\n", ans);
	return 0;
}