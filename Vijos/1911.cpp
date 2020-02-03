#include <cstdio>
#include <cstring>
using namespace std;

int a[101];
bool used[101];
int n, i, j, k;
int ans = 0;

int main()
{
	//freopen("count.in","r",stdin);freopen("count.out","r",stdin);
	memset(used, false, sizeof(used));
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = j + 1; k <= n; k++)
			{
				if (a[j] + a[k] == a[i] && !used[i])
				{
					ans++;
					used[i] = true;
				}
			}
	printf("%d", ans);
	return 0;
}