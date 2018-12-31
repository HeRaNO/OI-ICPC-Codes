//Code By HeRaNO
#include <iostream>
using namespace std;
int i, maxn, maxd, m, n, s;
int main()
{
	for (i = 1; i <= 7; i++)
	{
		cin >> m >> n;
		s = m + n;
		if (s > 8 && s > maxn)
		{
			maxn = s;
			maxd = i;
		}
	}
	cout << maxd;
	return 0;
}
