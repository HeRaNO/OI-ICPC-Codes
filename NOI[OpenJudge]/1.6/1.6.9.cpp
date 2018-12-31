//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int n, i;
	int a[1001], b[1001];
	long long ans = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (i = 1; i <= n; i++)
		ans += a[i] * b[i];
	cout << ans;
	return 0;
}