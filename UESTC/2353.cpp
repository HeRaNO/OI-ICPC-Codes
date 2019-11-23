#include <bits/stdc++.h>
using namespace std;

int n, m, mn, k, t;
int cnt;

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &t);
	if (k > n) k = n;
	if ((n * m) % k) cnt = (n * m) / k + 1;
	else cnt = n * m / k;
	printf("%d\n", cnt * t);
	return 0;
}
