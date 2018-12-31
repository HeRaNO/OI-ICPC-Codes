//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int chang, m;
	cin >> chang;
	int a[chang - 1];
	for (int i = 0; i <= chang - 1; i++)
		cin >> a[i];
	for (int i = chang - 1; i >= 0; i--)
		cout << a[i] << " ";
}
