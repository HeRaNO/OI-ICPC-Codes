#include <iostream>
#include <cstdio>
using namespace std;

unsigned long long work(int n)
{
	if (n == 0) return 1;
	return work(n - 1) * (4 * n - 2) / (n + 1);
}

int main()
{
	int k;
	cin >> k;
	cout << work(k);
	return 0;
}
