//Code By HeRaNO
#include <iostream>
#include<iostream>
using namespace std;

int tot;
char a1, b1, c1;

void move(int n, char a, char b, char c)
{
	if (n == 1)cout << a << "->" << n << "->" << b << endl;
	else
	{
		move(n - 1, a, c, b);
		cout << a << "->" << n << "->" << b << endl;
		move(n - 1, c, b, a);
	}
}

int main()
{
	cin >> tot >> a1 >> b1 >> c1;
	move(tot, a1, b1, c1);
	return 0;
}
