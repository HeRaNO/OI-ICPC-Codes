#include <cstdio>
#include <algorithm>
int a[100010];
using namespace std;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	printf("%d", a[n - k + 1]);
	return 0;
}