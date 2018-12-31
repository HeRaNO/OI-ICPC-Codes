#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
using namespace std;

int a[MAXN][MAXN];
int n, m, cnt;
int father[MAXN];
int block, x;
bool vis[MAXN];
int left = 1, right = 1e8, middle, ans;

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

bool check(int k)
{
	for (int i = 0; i < MAXN; i++) father[i] = i;
	int sum = n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
		{
			if (getfather(i) != getfather(j) && a[i][j] <= k)
			{
				father[getfather(j)] = getfather(i);
				sum--;
			}
		}
	return sum >= m;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	while (left < right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) left = middle + 1;
		else right = middle;
	}
	printf("%d\n", right);
	return 0;
}
