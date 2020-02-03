#include <iostream>
#include <cmath>
using namespace std;
int num[10];
int n;
bool yhr(long a)
{
	if (a == 1)
		return 0;
	long c, i;
	double d;
	d = sqrt(a);
	c = floor(d);
	for (i = 2; i <= c; i++)
		if (a % i == 0)
			return 0;
	return 1;
}
int build(int a)
{
	int i, ans = 0, k = 1;
	for (i = a; i >= 1; i--)
	{
		ans += num[i] * k;
		k *= 10;
	}
	return ans;
}
void dfs(int a)
{
	int i, ll;
	bool flag;
	if (a == n + 1)
	{
		for (i = 1; i <= n; i++)
			cout << num[i];
		cout << endl;
	}
	for (i = 1; i <= 9; i++)
	{
		num[a] = i;
		ll = build(a);
		flag = yhr(ll);
		if (flag == 1)
			dfs(a + 1);
	}
}
int main()
{
	cin >> n;
	dfs(1);
	return 0;
}