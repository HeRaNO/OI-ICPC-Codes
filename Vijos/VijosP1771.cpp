#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

struct swiss
{
	int score;
	int s;
	int num;
};

bool cmp(swiss a, swiss b)
{
	return a.score == b.score ? a.num<b.num : a.score>b.score;
}

swiss all[MAXN], win[MAXN], lose[MAXN];
int n, r, q;
int i, j;
int win_p, lose_p;

int main()
{
	scanf("%d %d %d", &n, &r, &q);
	for (i = 1; i <= 2 * n; i++)
	{
		scanf("%d", &all[i].score);
		all[i].num = i;
	}
	for (i = 1; i <= 2 * n; i++)
		scanf("%d", &all[i].s);
	sort(all + 1, all + 2 * n + 1, cmp);
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (all[j * 2 - 1].s <= all[j * 2].s)
				swap(all[j * 2 - 1], all[j * 2]);
			all[j * 2 - 1].score++;
			win[j] = all[j * 2 - 1];
			lose[j] = all[j * 2];
		}
		win_p = 1;
		lose_p = 1;
		for (j = 1; j <= n * 2; j++)
		{
			if (win_p <= n && (lose_p > n || win[win_p].score > lose[lose_p].score || (win[win_p].score == lose[lose_p].score && win[win_p].num < lose[lose_p].num)))
			{
				all[j] = win[win_p];
				win_p++;
			}
			else
			{
				all[j] = lose[lose_p];
				lose_p++;
			}
		}
	}
	printf("%d", all[q].num);
	return 0;
}
//AC100 ^_^