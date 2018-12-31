#include <cstdio>
#include <cstring>
using namespace std;
int a[5000], b[2000];
int main()
{
	memset(a, 0, sizeof(a));
	int n, i, out_num = 0, ipos;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		a[b[i]]++;
	}
	int ans = 0;
	for (i = 0; i <= 1000; i++)
		if (a[i] > 0)
			ans++;
	printf("%d\n", ans);
	for (i = 0; i <= 1000; i++)
		if (a[i])
		{
			printf("%d ", i);
			out_num++;
			if (out_num == ans - 1)
			{
				ipos = i;
				break;
			}
		}
	for (i = ipos + 1; i <= 1000; i++)
		if (a[i])
			printf("%d", i);
	printf("\n");
	return 0;
}
