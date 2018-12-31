//Code By HeRaNO
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int h, w, p;
	char a;
	cin >> h >> w >> a >> p;
	if (p == 1)
		for (int i = 1; i <= h; ++i)
		{
			for (int i = 1; i <= w; ++i)
				cout << a;
			cout << endl;
		}
	else
		for (int i = 1; i <= h; ++i)
		{
			if (i == 1 || i == h)
			{
				for (int i = 1; i <= w; ++i)
					cout << a;
				cout << endl;
			}
			else
			{
				cout << a;
				for (int i = 1; i <= w - 2; ++i)
					cout << " ";
				cout << a << endl;
			}
		}
	return 0;
}