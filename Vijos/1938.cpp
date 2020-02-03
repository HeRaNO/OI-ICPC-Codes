#include<iostream>
#include <string>
int main()
{
	std::string a, b;
	std::cin >> a;
	std::cin >> b;
	int aa = 0, bb = 0;
	for (int i = 0; i <= a.length() - 1; i++)
	{
		if (a[i] == '0')
		{
			aa = aa + 6;
			continue;
		}
		if (a[i] == '1')
		{
			aa = aa + 2;
			continue;
		}
		if (a[i] == '2')
		{
			aa = aa + 5;
			continue;
		}
		if (a[i] == '3')
		{
			aa = aa + 5;
			continue;
		}
		if (a[i] == '4')
		{
			aa = aa + 4;
			continue;
		}
		if (a[i] == '5')
		{
			aa = aa + 5;
			continue;
		}
		if (a[i] == '6')
		{
			aa = aa + 6;
			continue;
		}
		if (a[i] == '7')
		{
			aa = aa + 3;
			continue;
		}
		if (a[i] == '8')
		{
			aa = aa + 7;
			continue;
		}
		if (a[i] == '9')
		{
			aa = aa + 6;
			continue;
		}
	}
	for (int i = 0; i <= b.length() - 1; i++)
	{
		if (b[i] == '0')
		{
			bb = bb + 6;
			continue;
		}
		if (b[i] == '1')
		{
			bb = bb + 2;
			continue;
		}
		if (b[i] == '2')
		{
			bb = bb + 5;
			continue;
		}
		if (b[i] == '3')
		{
			bb = bb + 5;
			continue;
		}
		if (b[i] == '4')
		{
			bb = bb + 4;
			continue;
		}
		if (b[i] == '5')
		{
			bb = bb + 5;
			continue;
		}
		if (b[i] == '6')
		{
			bb = bb + 6;
			continue;
		}
		if (b[i] == '7')
		{
			bb = bb + 3;
			continue;
		}
		if (b[i] == '8')
		{
			bb = bb + 7;
			continue;
		}
		if (b[i] == '9')
		{
			bb = bb + 6;
			continue;
		}
	}
	std::cout << aa - bb;
	return 0;
}