#include<iostream>
using namespace std;
int a, n = 1;
double sum;
int main()
{
	cin >> a;
	while (sum <= a)
	{
		sum += 1.0 / (double)n;
		n++;
	}
	cout << n - 1 << endl;
	return 0;
}
