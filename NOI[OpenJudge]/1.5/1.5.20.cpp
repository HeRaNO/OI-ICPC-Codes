//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	double h, h1, s = 0;
	cin >> h;
	h1 = h;
	for (int i = 1; i <= 10; i++)
	{
		s = h * 2 + s;
		h = h / 2;
	}
	cout << s - h1 << endl << h;
	return 0;
}