#include <iostream>
#include <cmath>
using namespace std;
int gcd(int m, int n)
{
	return m % n == 0 ? n : gcd(n, m % n);
}
int main()
{
	int x, y, i, v, s, ans;
	cin >> x >> y;
	v = x * y;
	s = (int)sqrt(v);
	ans = 0;
	for (i = x; i <= s; i++)
		if ((v % i == 0) && (gcd(v / i, i) == x)) ans++;
	ans *= 2;
	cout << ans;
	return 0;
}
