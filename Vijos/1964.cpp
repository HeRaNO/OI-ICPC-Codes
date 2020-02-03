#include <iostream>
using namespace std;
long long int n, m, s = 0, t = 1;
int main()
{
	cin >> n >> m;
	if (n >= m)n = m;
	for (long long int i = 1; i <= n; i++)
	{
		t = (t * i) % m;
		s = (s + t) % m;
	}
	cout << s % m;
	return 0;
}