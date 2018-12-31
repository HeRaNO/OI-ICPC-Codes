//Code By HeRaNO
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double n;
	cin >> n;
	int i, j, temp = 0;
	for (i = 30; ~i; i--)
		if (pow(2.0, i) <= n)
		{
			temp++;
			n -= pow(2.0, i);
		}
	cout << temp;
	return 0;
}
