#include <cstdio>
#define MAXN 100010
using namespace std;

int a[MAXN], b[MAXN];
long long f[MAXN], s[MAXN];
int n, L, r;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline bool check(int x)
{
	for (int i = 1; i <= n; i++) b[i] = a[i] - x;
	for (int i = 1; i <= n; i++) f[i] = mymax(0, f[i - 1] + (long long)b[i]), s[i] = s[i - 1] + (long long)b[i];
	for (int i = 1; i <= n - L + 1; i++)
		if (s[i + L - 1] - s[i - 1] + f[i - 1] >= 0) return true;
	return false;
}

inline int Binary()
{
	int l = 0, mid, ans;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &L);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] *= 1000, r = mymax(r, a[i]);
	printf("%d\n", Binary());
	return 0;
}