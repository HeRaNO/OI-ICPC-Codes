//Code By HeRaNO
#include <iostream>
using namespace std;
int main()
{
	int w, t, m, i;
	m = 0;
	t = 0;
	cin >> w;
	if (w >= 1 && w <= 7) m = 6 - w;
	else if (w >= 6 && w <= 7) m = 13 - w;
	int a[15] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	for (i = 0; i <= 11; i++)
		if ((a[i] + 13 - m) % 7 == 0)
			cout << i + 1 << endl;
	return 0;
}
