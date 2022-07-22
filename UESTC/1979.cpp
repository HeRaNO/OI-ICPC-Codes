#include <cstdio>
#include <cstring>

const int MAXN = 20'000'005;
const int MAXM = 205;
const int M = 1'000'000'007;

int head[MAXN], to[MAXN], nxt[MAXN], val[MAXN], cnt, N;
char ch[MAXN], s[MAXM];

void add(int x, int y, int z)
{
	to[cnt] = y; ch[cnt] = z; nxt[cnt] = head[x];
	head[x] = cnt++;
}

void fadd(int &x, int y){ x += y; if (x >= M) x -= M; return ; }

int main()
{
	memset(head, -1, sizeof head);
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++)
	{
		scanf("%s %d", s, &x);
		int now = 0;
		for (int j = 0; s[j]; j++)
		{
			int c = -1;
			for (int i = head[now]; ~i && !~c; i = nxt[i])
				if (ch[i] == s[j])
					c = to[i];
			if (!~c) add(now, ++N, s[j]), now = N;
			else now = c;
			fadd(val[now], x);
		}
	}
	scanf("%d", &n);
	for (int i = 0, k; i < n; i++)
	{
		int ans = 0;
		scanf("%s %d", s, &k);
		int now = 0;
		for (int j = 0; s[j]; j++)
		{
			int c = -1;
			for (int i = head[now]; ~i && !~c; i = nxt[i])
				if (ch[i] == s[j])
					c = to[i];
			if (!~c) break;
			now = c;
			fadd(ans, val[now]);
		}
		printf("%d\n", 1LL * ans * k % M);
	}
	return 0;
}