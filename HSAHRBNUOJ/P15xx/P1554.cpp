#include <cstdio>
#include <cstring>
using namespace std;

bool appear[10];
int n, q, tmp;
int len, ans;

int main()
{
	scanf("%d %d", &n, &q);
	memset(appear, false, sizeof(appear));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		if (!appear[tmp])
		{
			appear[tmp] = true;
			len++;
		}
		if (len == q)
		{
			ans++;
			len = 0;
			memset(appear, false, sizeof(appear));
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
