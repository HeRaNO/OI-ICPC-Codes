#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[2510], b[2510];
int f[2510];
int i, j, n, d, flagh = 0, flagj = 0;
char flag[2510];
int main()
{
	memset(f, 30000, sizeof(f));
	f[0] = 0;
	cin >> n >> d;
	for (i = 1; i <= n; i++)
	{
		cin >> flag[i];
		if (flag[i] == 'H')
		{
			flagh++;
			a[i] = flagh;
			b[i] = flagj;
		}
		else
		{
			flagj++;
			a[i] = flagh;
			b[i] = flagj;
		}
	}
	for (i = 1; i <= n; i++)
		for (j = 0; j < i; j++)
		{
			if (abs((a[i] - a[j]) - (b[i] - b[j])) <= d || a[i] == a[j] || b[i] == b[j])
				f[i] = min(f[i], f[j] + 1);
		}
	cout << f[n];
	return 0;
}