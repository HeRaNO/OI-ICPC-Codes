//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;
	if (a > b) cout << ">";
	else if (a == b) cout << "=";
	else cout << "<";
	return 0;
}