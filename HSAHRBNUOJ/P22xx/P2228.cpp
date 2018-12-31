#include <cstdio>
#include <cstring>
#define MAXN 500010
using namespace std;

int tree[MAXN][2];
int dp[MAXN][2];
int siz = 1;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void Build_A_Tree(int node)
{
	char c = getchar();
	if (c == '0') return ;
	siz++;
	tree[node][0] = siz;
	Build_A_Tree(siz);
	if (c == '2')
	{
		siz++;
		tree[node][1] = siz;
		Build_A_Tree(siz);
	}
}

void dp1(int node)
{
	if (!node) return ;
	dp1(tree[node][0]);
	dp1(tree[node][1]);
	dp[node][0] = mymax(dp[tree[node][0]][0] + dp[tree[node][1]][1], dp[tree[node][0]][1] + dp[tree[node][1]][0]);
	dp[node][1] = dp[tree[node][0]][0] + dp[tree[node][1]][0] + 1;
}

void dp2(int node)
{
	if (!node) return ;
	dp2(tree[node][0]);
	dp2(tree[node][1]);
	dp[node][0] = mymin(dp[tree[node][0]][0] + dp[tree[node][1]][1], dp[tree[node][0]][1] + dp[tree[node][1]][0]);
	dp[node][1] = dp[tree[node][0]][0] + dp[tree[node][1]][0] + 1;
}

int main()
{
	Build_A_Tree(1);
	dp1(1);
	printf("%d ", mymax(dp[1][0], dp[1][1]));
	memset(dp, 0, sizeof(dp));
	dp2(1);
	printf("%d\n", mymin(dp[1][0], dp[1][1]));
	return 0;
}
