//Code By HeRaNO
#include <iostream>
#include <algorithm>
using namespace std;

int x[101], y[101];
int n;
int u[101];
int sum;

int main()
{
	cin >> n;
	for (int j = 1; j <= n; j++)
		cin >> x[j] >> y[j];
	for (int j = 1; j <= n; j++)
	{
		bool p = 1;
		for (int i = 1; i <= n; i++)
		{
			if ((i != j) && x[i] >= x[j] && y[i] >= y[j])
			{
				p = 0;
				break;
			}
		}
		if (p == 1)
		{
			sum++;
			u[sum] = 1000 * x[j] + y[j];
		}
	}
	if (sum == 1) cout << '(' << (u[1] - u[1] % 1000) / 1000 << ',' << u[1] % 1000 << ')' << endl;
	else
	{
		sort(u + 1, u + sum + 1);
		for (int j = 1; j <= sum - 1; j++)
			cout << '(' << (u[j] - u[j] % 1000) / 1000 << ',' << u[j] % 1000 << ')' << ',';
		cout << '(' << (u[sum] - u[sum] % 1000) / 1000 << ',' << u[sum] % 1000 << ')' << endl;
	}
	return 0;
}
