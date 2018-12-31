#include <cstdio>
using namespace std;

int n, x, y, k;
int bk, ak;

int mymin(int a, int b, int c, int d)
{
	int minl = a;
	if (b < minl) minl = b;
	if (c < minl) minl = c;
	if (d < minl) minl = d;
	return minl;
}

int main()
{
	//freopen("matrix.in","r",stdin);freopen("matrix.out","w",stdout);
	scanf("%d %d %d", &n, &x, &y);
	k = mymin(x, y, n - x + 1, n - y + 1);
	bk = 4 * (n + (k - 2) * (n - k) - 1) + 1;
	ak = n - 2 * (k - 1);
	if (x == k) printf("%d", bk + y - k);
	else if (y == k + ak - 1) printf("%d", bk + ak - 1 + x - k);
	else if (x == k + ak - 1) printf("%d", bk + 3 * ak + k - 3 - y);
	else printf("%d", bk + 4 * ak + k - 4 - x);
	puts("");
	return 0;
}
