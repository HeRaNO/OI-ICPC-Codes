#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 3100
using namespace std;

struct edge
{
	int from;
	int to;
	int len;
};

vector <edge> e;
int father[MAXN];
bool cun[MAXN][MAXN] = {false};
int n, m;
int i, j, flag;
int ans;

bool cmp(edge a, edge b)
{
	return a.len < b.len;
}

int getfather(int x)
{
	return father[x] == x ? x : father[x] = getfather(father[x]);
}

void kruskal()
{
	int jia = 0;
	for (int i = 0; i < m; i++)
	{
		if (jia == n) return ;
		int x = getfather(e[i].from);
		int y = getfather(e[i].to);
		if (x != y)
		{
			ans += e[i].len;
			father[y] = x;
			jia++;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		father[i] = i;
		scanf("%d", &flag);
		e.push_back((edge)
		{
			0, i, flag
		});
		m++;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &flag);
			if (cun[i][j] || i == j) continue;
			else
			{
				e.push_back((edge)
				{
					i, j, flag
				});
				m++;
				cun[i][j] = cun[j][i] = true;
			}
		}
	sort(e.begin(), e.end(), cmp);
	kruskal();
	printf("%d\n", ans);
	return 0;
}
