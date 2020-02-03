#include <cstdio>
#include <iostream>
using namespace std;

int sum[2][100005];
int color[100005];
int d[2][100005];
int val[100005];
int n, m;

int main()
{
	cin >> n >> m;
	int i, ans = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		val[i] %= 10007;
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &color[i]);
		sum[i % 2][color[i]] += val[i];
		sum[i % 2][color[i]] %= 10007;
		d[i % 2][color[i]]++;
	}
	for (i = 1; i <= n; i++)
		ans = (ans + i % 10007 * ((sum[i % 2][color[i]] + (d[i % 2][color[i]] - 2) % 10007 * val[i] + 10007) % 10007)) % 10007;
	cout << ans << endl;
	return 0;
}