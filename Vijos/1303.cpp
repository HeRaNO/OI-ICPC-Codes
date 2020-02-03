#include <iostream>
#include <cstdio>
using namespace std;

int a[21] = {0};
int dp1[21] = {0}, dp2[21] = {0};
int ans1 = 0, ans2 = 0, i, j, n, maxl, x;

int main()
{
	i = 1;
	scanf("%d", &a[i]);
	i++;
	while (scanf(",%d", &a[i]))
		i++;
	n = i;
	dp1[1] = 1;
	dp2[1] = 1;
	for (i = 2; i <= n; i++)
	{
		maxl = 0;
		for (j = 1; j <= i; j++)
			if (maxl < dp1[j] && a[j] > a[i]) maxl = dp1[j];
		dp1[i] = maxl + 1;
		if (dp1[i] > ans1) ans1 = dp1[i];
	}
	for (i = 2; i <= n; i++)
	{
		maxl = 0;
		for (j = 1; j <= i; j++)
			if (maxl < dp2[j] && a[j] < a[i]) maxl = dp2[j];
		dp2[i] = maxl + 1;
		if (dp2[i] > ans2) ans2 = dp2[i];
	}
	cout << ans1 - 1 << "," << ans2 - 1 << endl;
	return 0;
}
