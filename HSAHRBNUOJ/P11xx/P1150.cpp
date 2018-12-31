#include <iostream>
using namespace std;
int main()
{
	int n, i = 1, ans = 0;
	cin >> n;
	while (n)
	{
		if (n >= i)
		{
			n -= i;
			ans += i * i;
		}
		else
		{
			ans += i * n;
			n = 0;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}
