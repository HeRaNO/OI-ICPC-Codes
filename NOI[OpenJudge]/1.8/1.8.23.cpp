//Code By HeRaNO
#include<iostream>
#include<cstring>
using namespace std;
int a[100 + 5][100 + 5], y, x, s;
void deal(int m, int n, int f)
{
	cout << a[m][n] << endl;
	a[m][n] = -1;
	s--;
	if (s == 0) return ;
	if (f == 0)
	{
		if (a[m][n + 1] != -1) deal(m, n + 1, 0);
		else deal(m + 1, n, 1);
	}
	if (f == 1)
	{
		if (a[m + 1][n] != -1) deal(m + 1, n, 1);
		else deal(m, n - 1, 2);
	}
	if (f == 2)
	{
		if (a[m][n - 1] != -1) deal(m, n - 1, 2);
		else deal(m - 1, n, 3);
	}
	if (f == 3)
	{
		if (a[m - 1][n] != -1) deal(m - 1, n, 3);
		else deal(m, n + 1, 0);
	}
}
int main()
{
	memset(a, -1, sizeof(a));
	int i, j, l, c = 0;
	cin >> x >> y;
	s = x * y;
	for (i = 1; i <= x; i++)
		for (j = 1; j <= y; j++)
			cin >> a[i][j];
	deal(1, 1, 0);
	return 0;
}
