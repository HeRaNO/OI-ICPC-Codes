#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
#define MAXL 110
using namespace std;

int n, m;
char a[MAXN][MAXL];
int len[MAXN], id[MAXN];

bool cmp(int aa, int bb)
{
	if (len[aa] != len[bb]) return len[aa] < len[bb];
	for (int i = m; i < len[aa]; i++)
		if (a[aa][i] != a[bb][i])
			return a[aa][i] < a[bb][i];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", a[i]);
		len[i] = strlen(a[i]);
		id[i] = i;
	}
	for (m = 0; a[1][m] < '0' || a[1][m] > '9'; m++);
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) puts(a[id[i]]);
	return 0;
}
