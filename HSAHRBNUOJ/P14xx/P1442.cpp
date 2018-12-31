#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
	int next[26];
	node()
	{
		memset(next, -1, sizeof(next));
	}
} T[200000];

int ans;
int tot;
char str[100];

void insert()
{
	int root = 0, t;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		t = str[i] - 'A';
		if (T[root].next[t] == -1)
		{
			ans++;
			T[root].next[t] = tot++;
		}
		root = T[root].next[t];
	}
}

int main()
{
	ans = 1;
	tot = 1;
	memset(T, -1, sizeof(T));
	while (scanf("%s", str) != EOF) insert();
	printf("%d\n", ans);
	return 0;
}
