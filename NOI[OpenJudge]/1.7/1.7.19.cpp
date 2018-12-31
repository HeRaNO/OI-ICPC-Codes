//Code By HeRaNO
#include <cstring>
#include <iostream>
using namespace std;

string tops(string a)
{
	string k = a;
	for (int i = 0; i < a.length() - 1; i++)
		k[i] = k[i + 1];
	k[a.length() - 1] = a[0];
	return k;
}

bool check(string a, string b)
{
	int k = 0;
	if (b == a)return true;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[0])
		{
			for (int j = 0; j < b.length(); j++)
			{
				if (a[i + j] != b[j])break;
				if (j == b.length() - 1)return true;
			}
		}
	}
	return false;
}

int main()
{
	string a, b;
	cin >> a >> b;
	if (a == b)
	{
		cout << "true";
		return 0;
	}
	string a1 = a, b1 = b;
	for (int i = 0; i < a.length() + 1; i++)
	{
		a1 = tops(a1);
		if (check(a1, b))
		{
			cout << "true";
			return 0;
		}
	}
	for (int i = 0; i < b.length() + 1; i++)
	{
		b1 = tops(b1);
		if (check(b1, a))
		{
			cout << "true";
			return 0;
		}
	}
	cout << "false";
	return 0;
}
