//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int a, b3, b5, b7;
	cin >> a;
	b3 = a % 3;
	b5 = a % 5;
	b7 = a % 7;
	if ((b3 == 0) && (b5 == 0) && (b7 == 0)) cout << "3 5 7";
	else if ((b3 == 0) && (b5 == 0)) cout << "3 5";
	else if ((b3 == 0) && (b7 == 0)) cout << "3 7";
	else if ((b5 == 0) && (b7 == 0)) cout << "5 7";
	else if (b3 == 0) cout << "3";
	else if (b5 == 0) cout << "5";
	else if (b7 == 0) cout << "7";
	else cout << "n";
	return 0;
}
