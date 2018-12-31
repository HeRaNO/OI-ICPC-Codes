#include <iostream>
using namespace std;
int n, m, x, s;
int main()
{
	cin >> n >> m;
	x = m / 2 + m % 2 - 1;
	s = (n / m) * x + 1 + (m + 1) % 2;
	if (n % m > x) n = x;
	else n %= m;
	s += n;
	cout << s;
	return 0;
}
