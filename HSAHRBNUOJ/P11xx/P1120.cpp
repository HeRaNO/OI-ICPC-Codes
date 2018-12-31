#include<iostream>
using namespace std;
int main()
{
	int m, n, i, v;
	int w[101], c[101], f[1001] = {0};
	cin >> m >> n;
	for (i = 1; i <= n; i++)
		cin >> w[i] >> c[i];
	for (i = 1; i <= n; i++)
		for (v = m; v >= w[i]; v--)
			if (f[v] < f[v - w[i]] + c[i])
				f[v] = f[v - w[i]] + c[i];
	cout << f[m] << endl;
	return 0;
}
