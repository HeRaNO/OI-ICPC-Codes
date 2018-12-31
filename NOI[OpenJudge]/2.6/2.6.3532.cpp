//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 1005
using namespace std;

int a[MAXN], len[MAXN], maxsum[MAXN];
int n, ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	for (int i = 0; i < MAXN; i++) len[i] = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		maxsum[i] = a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if (a[i] < a[j] && len[i] >= len[j])
			{
				len[j] = len[i] + 1;
				maxsum[j] = mymax(maxsum[j], maxsum[i] + a[j]);
			}
		}
	for (int i = 1; i <= n; i++)
		ans = mymax(ans, maxsum[i]);
	printf("%d\n", ans);
	return 0;
}
