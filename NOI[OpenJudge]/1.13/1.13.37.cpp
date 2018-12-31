//Code By HeRaNO
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
char s[1000000];
int main()
{
	int i = 0;
	while (1)
	{
		cin >> s[i];
		if (s[i] == 'E') break;
		i++;
		if (i % 20 == 0)getchar();
	}
	int a = 0, b = 0, j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == 'W')a++;
		else if (s[j] == 'L')b++;
		j++;
		if ((a >= 11 && a - b >= 2) || (b >= 11 && b - a >= 2) || s[j - 1] == 'E')
		{
			cout << a << ':' << b << endl;
			a = 0;
			b = 0;
			continue;
		}
	}
	cout << endl;
	j = 0;
	a = 0;
	b = 0;
	while (s[j] != '\0')
	{
		if (s[j] == 'W')a++;
		else if (s[j] == 'L')b++;
		j++;
		if ((a >= 21 && a - b >= 2) || (b >= 21 && b - a >= 2) || s[j - 1] == 'E')
		{
			cout << a << ':' << b << endl;
			a = 0;
			b = 0;
			continue;
		}
	}
	return 0;
}
