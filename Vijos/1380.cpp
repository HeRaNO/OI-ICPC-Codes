#include <iostream>
using namespace std;
int jing[1001], a, b, i, j, ans = 0, m;
int main()
{
	cin >> a >> b;
	for (i = 1; i <= a; i++)
		cin >> jing[i];
	for (i = 1; i <= a - 1; i++)
		for (j = i + 1; j <= a; j++)
		{
			if (i * jing[i] == j * jing[j])
			{
				m = (i + j) >> 1;
				break;
			}
		}
	if (b == 0)
	{
		for (i = 1; i <= m; i++)
			ans += jing[i];
	}
	else
	{
		for (i = a; i >= m; i--)
			ans += jing[i];
	}
	cout << m << " " << ans;
	return 0;
}
