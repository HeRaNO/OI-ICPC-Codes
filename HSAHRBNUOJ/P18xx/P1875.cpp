#include <cstdio>
#define MAXN 100010
using namespace std;

int c, n, k, ans;
char s[MAXN];
int prec[MAXN];
int left, right, middle;

bool check(int limit)
{
	for (int i = 1; i + limit <= c; i++)
		if (prec[i + limit] - prec[i] >= n - k) return true;
	return false;
}

int main()
{
	//freopen("chairs.in","r",stdin);freopen("chairs.out","w",stdout);
	scanf("%d %d %d", &c, &n, &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= c; i++) prec[i] = prec[i - 1] + (s[i] == 'd');
	left = n;
	right = c;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) right = middle - 1, ans = middle;
		else left = middle + 1;
	}
	printf("%d\n", ans);
	return 0;
}
