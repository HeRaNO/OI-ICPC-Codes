//Code By HeRaNO
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int abs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	int c;
	cin >> c;
	int a[c + 1];
	for (int i = 0; i <= c; i++)
		cin >> a[i];
	if (abs(a[0]) == 1)
	{
		if (a[0] == 1)
			cout << "x^" << c;
		if (a[0] == -1)
			cout << "-x^" << c;
	}
	else
		cout << a[0] << "x^" << c;
	for (int i = c - 1; i >= 0; i--)
	{
		if (a[c - i] == 0)
			continue;
		if (i == 1)
		{
			if (abs(a[c - i]) == 1)
			{
				if (a[c - i] > 0)
					cout << '+' << 'x';
				if (a[c - i] < 0)
					cout << '-' << 'x';
			}
			else if (a[c - i] > 0)
				cout << '+' << a[c - i] << 'x';
			if (a[c - i] < 0)
				cout << a[c - i] << 'x';
		}
		else if (i == 0)
		{
			if (a[c - i] > 0)
				cout << '+' << a[c - i];
			if (a[c - i] < 0)
				cout << a[c - i];
		}
		else if (abs(a[c - i]) == 1)
		{
			if (a[c - i] > 0)
				cout << '+' << "x^" << i;
			if (a[c - i] < 0)
				cout << '-' << "x^" << i;
		}
		else
		{
			if (a[c - i] > 0)
				cout << '+' << a[c - i] << "x^" << i;
			if (a[c - i] < 0)
				cout << a[c - i] << "x^" << i;
		}
	}
	cout << endl;
}
