#include<iostream>
using namespace std;
int i, n, a, sum[1001] = {0, 1};
int main()
{
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		a = sum[i / 2] + 1;
		sum[i] = sum[i - 1] + a;
	}
	cout << sum[n] - sum[n - 1] << endl;
	return 0;
}
