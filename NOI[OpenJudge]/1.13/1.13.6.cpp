//Code By HeRaNO
#include <cstring>
#include <iostream>
#define MAXL 70
using namespace std;

string a, b;
int aa[MAXL], c[MAXL];
int len;

bool judge()
{
	for (int i = len; i; i--)
		b[len - i] = c[i] + '0';
	if (a.find(b) == string::npos) return false;
	else return true;
}

int main()
{
	cin >> a;
	len = a.length();
	int i = 0;
	while (len)
	{
		len--;
		i++;
		aa[i] = a[len] - '0';
	}
	len = a.length();
	b = a;
	a += a;
	for (int i = 2; i <= len; i++)
	{
		memset(c, 0, sizeof(c));
		for (int j = 1; j <= len; j++)
			c[j] = aa[j] * i;
		for (int j = 1; j < len; j++)
		{
			c[j + 1] += c[j] / 10;
			c[j] %= 10;
		}
		if (c[len] > 9 || !judge())
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
