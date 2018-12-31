#include<cstdio>
#include<cstring>
using namespace std;
bool f[100010];
int a[7];
int b[7] = {0, 1, 2, 3, 5, 10, 20};
int sum, i, j, k, ans;
int main()
{
	for (int i = 1; i <= 6; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i] * b[i];
	}
	f[0] = 1;
	for (i = 1; i <= 6; i++)
		for (j = 1; j <= a[i]; j++)
			for (k = sum; k >= b[i]; k--)
				if (f[k - b[i]]) f[k] = 1;
	for (i = 1; i <= sum; i++) if (f[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
