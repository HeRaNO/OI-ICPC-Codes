#include <cstring>
#include <iostream>
using namespace std;

string n;
int m;

int main()
{
	cin >> n;
	cin >> m;
	while (m)
	{
		int i = 0;
		while (i < n.length() - 1 && n[i] <= n[i + 1]) i++;
		n.erase(i, 1);
		m--;
	}
	while (n.length() > 1 && n[0] == '0') n.erase(0, 1);
	cout << n;
	return 0;
}
