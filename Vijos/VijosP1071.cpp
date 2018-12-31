#include<iostream>
#include<cstdio>
using namespace std;
int dp[100010] = {0}, w[110] = {0};
int path[100010] = {0};
int total, n, i, j, rest;
long sum = 0;
void print(int x)
{
	if (x == 0) return;
	print(x - w[path[x]]);
	printf("%d ", path[x]);
}
int main()
{
	cin >> total;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> w[i];
		sum += w[i];
	}
	rest = sum - total;
	dp[0] = 1;
	for (i = 1; i <= n; i++)
		for (j = rest; j >= w[i]; j--)
		{
			dp[j] += dp[j - w[i]];
			if (path[j] == 0 && dp[j - w[i]] != 0) path[j] = i;
		}
	if (dp[rest] == 0) printf("0");
	else if (dp[rest] > 1) printf("-1");
	else print(rest);
	return 0;
}
