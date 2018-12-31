#include <cstdio>
#include <climits>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct mining
{
	int mine;
	int pos;
};

mining a[MAXN];
int dp[MAXN], posmax[MAXN];
int n, m;

bool judge(int aa, int bb)
{
	int dis = a[aa].pos - a[bb].pos;
	if (dis > 17) return true;
	if (dis == 0 || dis == 4 || dis == 7 || dis == 8 || dis == 11 || dis == 12 || dis == 14 || dis == 15 || dis == 16) return true;
	else return false;
}

bool cmp(mining a, mining b)
{
	return a.pos < b.pos;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("mining.in","r",stdin);freopen("mining.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].mine, &a[i].pos);
	sort(a + 1, a + n + 1, cmp);
	a[0].pos = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = INT_MIN;
		int j;
		for (j = i - 1; a[i].pos - a[j].pos <= 17 && j; j--)
			if (judge(i, j)) dp[i] = mymax(dp[i], dp[j] + a[i].mine);
		if (judge(i, j)) dp[i] = mymax(dp[i], posmax[j] + a[i].mine);
		posmax[i] = mymax(posmax[i - 1], dp[i]);
	}
	printf("%d\n", posmax[n]);
	return 0;
}
