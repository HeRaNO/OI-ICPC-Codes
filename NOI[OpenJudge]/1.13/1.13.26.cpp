//Code By HeRaNO
#include <cstring>
#include <iostream>
#define MAXL 510
using namespace std;

int n;
string a[MAXL], s, t;
int num[MAXL];
int len, cnta;
bool found;
int maxp;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	cin >> n;
	cin >> s;
	len = s.length();
	for (int i = 0; i <= len - n; i++)
	{
		t = s.substr(i, n);
		found = false;
		for (int i = 1; i <= cnta; i++)
		{
			if (a[i] == t)
			{
				found = true;
				num[i]++;
				break;
			}
		}
		if (!found)
		{
			a[++cnta] = t;
			num[cnta]++;
		}
	}
	for (int i = 1; i <= cnta; i++) maxp = mymax(num[i], maxp);
	if (maxp <= 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		cout << maxp << endl;
		for (int i = 1; i <= cnta; i++)
			if (num[i] == maxp) cout << a[i] << endl;
	}
	return 0;
}
