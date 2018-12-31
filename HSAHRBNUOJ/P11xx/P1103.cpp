#include <iostream>
using namespace std;
int main()
{
	int f, a, b, c;
	cin >> f >> a >> b >> c;
	if (f == 1)
	{
		if (a < b)
		{
			if (a < c) cout << a;
			else cout << c;
		}
		else
		{
			if (b < c) cout << b;
			else cout << c;
		}
	}
	else
	{
		if (a > b)
		{
			if (b > c) cout << b;
			else if (a > c) cout << c;
			else cout << a;
		}
		else if (a > c) cout << a;
		else
		{
			if (b > c) cout << c;
			else cout << b;
		}
	}
	cout << endl;
	return 0;
}
