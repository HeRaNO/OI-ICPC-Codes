//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (((a + c) > b) && ((a + b) > c) && ((b + c) > a))
		cout << "yes";
	else cout << "no";
	return 0;
}