#include<iostream>
using namespace std;
long long n, f;
long long calc(long long n)
{
	if (n <= 1) return n;
	long long ans = 0;
	if (n % 2 == 0) ans += n / 2;
	else ans += n / 2 + 1;
	ans += calc(n / 4);
	return ans;
}
int main()
{
	cin >> n;
	cout << calc(n);
	return 0;
}
