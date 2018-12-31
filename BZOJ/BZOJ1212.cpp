#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 25
#define MAXL (1<<20)+10
#define maxl 15
using namespace std;

struct Tire
{
	int nxt[26];
	bool ed;
};

Tire tree[MAXN * maxl];
char word[maxl], S[MAXL];
int n, T, root, top;
bool understand[MAXL];

inline int newnode()
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top++].ed = false;
	return top - 1;
}

inline void add()
{
	int len = strlen(word), now = root;
	for (int i = 0; i < len; i++)
	{
		if (!~tree[now].nxt[word[i] - 'a']) tree[now].nxt[word[i] - 'a'] = newnode();
		now = tree[now].nxt[word[i] - 'a'];
	}
	tree[now].ed = true;
	return ;
}

inline int Solve()
{
	memset(understand, false, sizeof understand);
	understand[0] = true;
	int len = strlen(S + 1), res = 0;
	for (int i = 0; i <= len; i++)
	{
		if (!understand[i]) continue;
		res = i;
		for (int j = i + 1, now = 0; j <= len; j++)
		{
			now = tree[now].nxt[S[j] - 'a'];
			if (!~now) break;
			if (tree[now].ed) understand[j] = true;
		}
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &T);
	root = newnode();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", word);
		add();
	}
	while (T--)
	{
		scanf("%s", S + 1);
		printf("%d\n", Solve());
	}
	return 0;
}
