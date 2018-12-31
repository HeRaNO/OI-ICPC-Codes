//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n < 0)
		cout << "negative";
	else if (n == 0)
		cout << "zero";
	else cout << "positive";
	return 0;
}