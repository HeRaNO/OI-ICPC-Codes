#include <iostream>
using namespace std;

int a, b, c, zs;
int d[30], pos;

int main()
{
	//freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	cin >> a >> b;
	zs = a / b;
	c = a % b;
	if (!c)
	{
		cout << a << "/" << b << "=" << zs << ".0" << endl;
		return 0;
	}
	for (int i = 1; i <= 21; i++)
	{
		c = c * 10;
		d[i] = c / b;
		c = c % b;
	}
	if (d[21] >= 5) d[20]++;
	for (int i = 21; i; i--)
	{
		if (d[i])
		{
			pos = i;
			break;
		}
	}
	cout << a << "/" << b << "=" << zs << ".";
	if (pos >= 20) for (int i = 1; i <= 20; i++)cout << d[i];
	else for (int i = 1; i <= pos; i++)cout << d[i];
	cout << endl;
	return 0;
}
