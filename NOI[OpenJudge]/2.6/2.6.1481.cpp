//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 50010
using namespace std;

int a[MAXN];
int lmax[MAXN], rmax[MAXN];
int left[MAXN], right[MAXN];
int ans;
int n, t;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(lmax, 0, sizeof(lmax));
		memset(rmax, 0, sizeof(rmax));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		lmax[1] = a[1];
		for (int i = 2; i <= n; i++)
			if (lmax[i - 1] <= 0) lmax[i] = a[i];
			else lmax[i] = lmax[i - 1] + a[i];
		for (int i = 2; i <= n; i++)
			lmax[i] = mymax(lmax[i - 1], lmax[i]);
		rmax[n] = a[n];
		for (int i = n - 1; i; i--)
			if (rmax[i + 1] <= 0) rmax[i] = a[i];
			else rmax[i] = rmax[i + 1] + a[i];
		for (int i = n - 1; i; i--)
			rmax[i] = mymax(rmax[i + 1], rmax[i]);
		ans = a[1] + a[n];
		for (int i = 1; i < n; i++)
			ans = mymax(ans, lmax[i] + rmax[i + 1]);
		printf("%d\n", ans);
	}
	return 0;
}
