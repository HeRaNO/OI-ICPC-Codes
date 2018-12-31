//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	float a[20];
	float A[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
	for (int i = 0; i <= 9; i++) cin >> a[i];
	float sum = 0.0;
	for (int i = 0; i <= 9; i++)
		sum += a[i] * A[i];
	cout << sum;
	return 0;
}