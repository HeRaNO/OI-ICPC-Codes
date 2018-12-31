//Code By HeRaNO
#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	if (!(a % 2))
	{
		if (!(a % 4)) cout << a / 4 << " ";
		else cout << (a - 2) / 4 + 1 << " ";
		cout << a / 2 << endl;
	}
	else cout << "0 0" << endl;
	return 0;
}
