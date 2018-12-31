#include <cstdio>
#include <algorithm>
#define MAXN 6010
using namespace std;

struct exam
{
	int id;
	int score;
};

exam a[MAXN];
int n, m;
int need;
int pos;

bool cmp(exam a, exam b)
{
	if (a.score == b.score) return a.id < b.id;
	else return a.score > b.score;
}

int main()
{
	scanf("%d %d", &n, &m);
	need = m * 1.5;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].id, &a[i].score);
	sort(a + 1, a + n + 1, cmp);
	for (int i = need; i <= n; i++)
	{
		if (a[i].score != a[need].score)
		{
			pos = i - 1;
			break;
		}
	}
	printf("%d %d\n", a[need].score, pos);
	for (int i = 1; i <= pos; i++)
		printf("%d %d\n", a[i].id, a[i].score);
	return 0;
}