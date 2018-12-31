#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int a[10005];
int n, k;
int s = 0;
int isp(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return 0;
	return 1;
}
int dfs(int nw, int w, int t)
{
	if (w > n)
		return 0;
	if (nw == k)
	{
		if (isp(t) == 1)
			s++;
		return 0;
	}
	dfs(nw + 1, w + 1, t + a[w]);
	dfs(nw, w + 1, t);
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dfs(0, 0, 0);
	cout << s;
}