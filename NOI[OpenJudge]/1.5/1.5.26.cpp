//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int a, n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a % 10 - a / 1000 - a / 100 + 10 * (a / 1000) - (a % 100 - a % 10) / 10 > 0)
			ans++;
	}
	cout << ans;
	return 0;
}