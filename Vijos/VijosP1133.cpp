#include <iostream>
#include <cstring>
using namespace std;
int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int v, n;
	cin >> v >> n;
	int a[n];
	int dp[v + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = v; j >= a[i]; j--)
			dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
	}
	cout << v - dp[v];
}
