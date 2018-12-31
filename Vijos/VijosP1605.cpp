#include <cstdio>
#include <stack>
#include <climits>
#include <cstdlib>
#define MAXN 1005
using namespace std;

int color[MAXN];
bool road[MAXN][MAXN] = {false};
int num[MAXN];
int a[MAXN];
int small[MAXN];
int n, i, j;
int caozuo;
stack <int> s1;
stack <int> s2;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void lalala()
{
	printf("0");
	exit(0);
}
bool bcolor(int dep, int c)
{
	color[dep] = c;
	for (int i = 1; i <= n; i++)
	{
		if (road[dep][i])
		{
			if (color[i] == c)
				lalala();
			if (!color[i]) bcolor(i, 3 - c);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	small[n + 1] = INT_MAX;
	for (i = n; i >= 1; i--) small[i] = mymin(small[i + 1], a[i]);
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			if (a[i] < a[j] && small[j + 1] < a[i])
				road[i][j] = road[j][i] = true;
	for (i = 1; i <= n; i++)
	{
		if (!color[i])
			bcolor(i, 1);
	}
	int aim = 1;
	for (i = 1; i <= n; i++)
	{
		if (color[i] == 1)
		{
			caozuo++;
			if (caozuo < 2 * n)
				printf("a ");
			else printf("a");
			s1.push(a[i]);
		}
		else
		{
			caozuo++;
			if (caozuo < 2 * n)
				printf("c ");
			else printf("c");
			s2.push(a[i]);
		}
		while ((!s1.empty() && s1.top() == aim) || (!s2.empty() && s2.top() == aim))
		{
			if (!s1.empty() && s1.top() == aim)
			{
				caozuo++;
				if (caozuo < 2 * n)
					printf("b ");
				else printf("b");
				s1.pop();
			}
			else
			{
				caozuo++;
				if (caozuo < 2 * n)
					printf("d ");
				else printf("d");
				s2.pop();
			}
			aim++;
		}
	}
	return 0;
}