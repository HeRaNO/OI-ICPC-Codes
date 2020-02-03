#include<iostream>
using namespace std;
int main()
{
	int a;
	double sum = 0;
	cin >> a;
	int n = 1;
	while (sum <= a)
	{
		sum += 1.0 / n;
		n++;
	}
	cout << n - 1;
	return 0;
}
