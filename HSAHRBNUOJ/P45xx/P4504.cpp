#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 1010
#define MAXM 55
using namespace std;

int a[MAXM], b[MAXM];
int n, m1, m2;
int qa[MAXN], qb[MAXN], x[MAXN];

void Greed(int p[], int m, int q[])
{
	memset(x, 0, sizeof(x));
	int minn, pos;
	for (int i = 1; i <= n; i++)
	{
		minn = INT_MAX;
		for (int j = 1; j <= m; j++)
			if (p[j] + x[j] < minn)
			{
				minn = p[j] + x[j];
				pos = j;
			}
		x[pos] = minn, q[i] = minn;
	}
	return ;
}

bool check(int limit)
{
	for (int i = 1; i <= n; i++)
		if (qa[i] + qb[n - i + 1] > limit) return false;
	return true;
}

int binary()
{
	int left = 0, right = 5000000, middle, ans;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) ans = middle, right = middle - 1;
		else left = middle + 1;
	}
	return ans;
}

int main()
{
	//freopen("dvaloveu.in","r",stdin);freopen("dvaloveu.out","w",stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m2; i++) scanf("%d", &b[i]);
	Greed(a, m1, qa);
	Greed(b, m2, qb);
	printf("%d\n", binary());
	return 0;
}
