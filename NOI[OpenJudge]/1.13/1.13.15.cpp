//Code By HeRaNO
#include<iostream>
#include<cstring>
using namespace std;

int n, s, ma, m[200];
string a[200], b;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> b;
		if (b[0] == '-') while (b[1] == '0' && b.size() > 2) b.erase(1, 1);
		while ((b[0] == '0' || b[0] == '+') && b.size() > 1) b.erase(0, 1);
		if (b[0] == '-' && b[1] == '0')b.erase(0, 1);
		a[i] = b;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i] == a[j]) m[i]++;
	if (m[1] == n)
	{
		cout << "no";
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; ++i)
			if (m[i] > s) s = m[i], ma = i;
		cout << a[ma] << endl;
	}
	return 0;
}
