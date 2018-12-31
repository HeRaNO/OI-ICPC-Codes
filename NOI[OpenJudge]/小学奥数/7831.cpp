//Code By HeRaNO
#include<iostream>
using namespace std;
string s[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int quick_mod(int a, int b, int n)
{
	int d, t;
	d = 1;
	t = a;
	while (b > 0)
	{
		if (b % 2) d = d * t % n;
		b /= 2;
		t = t * t % n;
	}
	return d;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << s[quick_mod(a, b, 7)];
	return 0;
}
