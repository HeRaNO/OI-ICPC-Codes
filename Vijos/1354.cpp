#include<iostream>
using namespace std;
int main()
{
	int n, a[101] = {0}, i, j, t, o;
	cin >> n;
	a[1] = 1;
	for (i = 1; i <= n + 1; i++)
	{
		for (j = 1; j <= 100; j++)
			a[j] = a[j] * 2;
		for (j = 1; j <= 100; j++)
			if (a[j] > 9)
			{
				a[j] -= 10;
				a[j + 1] += 1;
			}
	}
	a[1] -= 2;
	for (j = 100; j > 0; j--)
		if (a[j] != 0)
		{
			o = j;
			break;
		}
	for (j = o; j > 0; j--)
		cout << a[j];
	return 0;
}