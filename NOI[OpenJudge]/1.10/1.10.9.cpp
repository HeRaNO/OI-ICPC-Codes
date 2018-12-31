//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 1001
using namespace std;

bool cnt[MAXN];
int a, n, ans;

int main()
{
	memset(cnt, false, sizeof(cnt));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		cnt[a] = true;
	}
	for (int i = 0; i <= MAXN; i++)
		if (cnt[i]) ans++;
	printf("%d\n", ans);
	for (int i = 0; i <= MAXN; i++)
		if (cnt[i]) printf("%d ", i);
	printf("\n");
	return 0;
}
