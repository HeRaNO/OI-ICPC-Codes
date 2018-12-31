#include<iostream>
using namespace std;
int main()
{
	int i, maxn = 0, maxd = 0, m, n, s;
	for (i = 1; i <= 7; i++)
	{
		cin >> m >> n;
		s = m + n;
		if ((s > 8) && (s > maxn))
		{
			maxn = s;
			maxd = i;
		}
	}
	cout << maxd << endl;
	return 0;
}
