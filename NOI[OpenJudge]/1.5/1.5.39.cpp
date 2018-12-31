//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int n, s = 0;
	cin >> n;
	for (int i = 0; i <= n; ++i)
	{
		if (i % 7 != 0 && i % 10 != 7 && i / 10 != 7)
			s = s + i * i;
	}
	cout << s;
	return 0;
}