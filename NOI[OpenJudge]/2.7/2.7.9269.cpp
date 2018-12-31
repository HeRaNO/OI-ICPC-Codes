#include<bits/stdc++.h>
using namespace std;
unsigned long long a[10000];
unsigned long long n;
int main()
{
	string C = "1234567";
	memset(a, 0, sizeof(a));
	a[0] = 4;
	a[1] = 3;
	for (int i = 2; i < 10000; i++)
		a[i] = a[i - 1] + a[i - 2];
	while (cin >> n)
	{
		while (n > 7)
		{
			int i = 0;
			while (a[i] < n) i++;
			n -= a[i - 1];
		}
		cout << C[n - 1] << endl;
	}
	return 0;
}
