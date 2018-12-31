#include<iostream>
#include<cstdio>
using namespace std;

int dp[100010], w[110];
int path[100010];
int total, n, i, j, rest;
int sum;
int num;
int cnt;

void print(int x)
{
	if (x == 0) return;
	cnt++;
	print(x - w[path[x]]);
	if (cnt == num)  printf("%d\n", path[x]);
	else  printf("%d ", path[x]);
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
	if (dp[rest] == 0) printf("0\n");
	else if (dp[rest] > 1) printf("-1\n");
	else print(rest);
	return 0;
}
