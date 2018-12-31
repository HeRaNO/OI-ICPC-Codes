//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	long long n, i;
	cin >> n;
	if (n == 1)
	{
		cout << "End";
		return 0;
	}
	while (n > 1)
	{
		if (n % 2 == 0)
		{
			i = n / 2;
			cout << n << "/2=" << i << endl;
			n = i;
			if (n == 1) break;
		}
		else
		{
			i = n * 3 + 1;
			cout << n << "*3+1=" << i << endl;
			n = i;
			if (n == 1) break;
		}
	}
	cout << "End";
	return 0;
}
