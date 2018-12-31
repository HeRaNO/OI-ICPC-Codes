//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int k, m, i, r, flag = 0;
	cin >> m >> k;
	r = m;
	if (m % 19 == 0)
	{
		while (r > 0)
		{
			if (r % 10 == 3)flag++;
			r /= 10;
		}
		if (k == flag)cout << "YES";
		else cout << "NO";
	}
	else cout << "NO";
	return 0;
}
