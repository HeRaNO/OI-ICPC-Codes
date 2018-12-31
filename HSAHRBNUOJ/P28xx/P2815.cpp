#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 30010
#define MAXM 510
#define seed 101
#define SEED 131
#define mod 70177
#define MOD 92311
using namespace std;

struct answer
{
	char s[MAXM];
	bool operator < (const answer &a) const
	{
		return strcmp(s, a.s) < 0;
	}
};

struct hash_link
{
	int val;
	int cnt;
	int nxt;
};

hash_link e[MAXN * 2];
answer a[MAXN];
int n, m, p, q, ecnt;
int edge_num[mod];
int h1[MAXN], h2[MAXN];
char nowans[MAXM];

inline void add(int x, int y)
{
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].val == y)
		{
			e[i].cnt++;
			return ;
		}
	e[ecnt] = (hash_link)
	{
		y, 1, edge_num[x]
	};
	edge_num[x] = ecnt++;
	return ;
}

inline int query(int x, int y)
{
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].val == y) return e[i].cnt;
	return 0;
}

inline void special_1()
{
	int hash1, hash2, ans = -1;
	for (int i = 1; i <= n; i++)
	{
		hash1 = hash2 = 0;
		for (int j = 0; j < m; j++)
		{
			hash1 = (hash1 * seed + (a[i].s[j] == 'N')) % mod;
			hash2 = (hash2 * SEED + (a[i].s[j] == 'N')) % MOD;
		}
		h1[i] = hash1;
		h2[i] = hash2;
		add(hash1, hash2);
	}
	for (int i = 1; i <= n; i++)
		if (query(h1[i], h2[i]) == p)
		{
			hash1 = hash2 = 0;
			for (int j = 0; j < m; j++)
			{
				hash1 = (hash1 * seed + (a[i].s[j] == 'Y')) % mod;
				hash2 = (hash2 * SEED + (a[i].s[j] == 'Y')) % MOD;
			}
			if (query(hash1, hash2) == q)
			{
				ans = i;
				break;
			}
		}
	if (ans != -1) puts(a[ans].s);
	else puts("-1");
	return ;
}

inline void special_2()
{
	int hash1, hash2, ans = -1;
	for (int i = 1; i <= n; i++)
	{
		hash1 = hash2 = 0;
		for (int j = 0; j < m; j++)
		{
			hash1 = (hash1 * seed + (a[i].s[j] == 'N')) % mod;
			hash2 = (hash2 * SEED + (a[i].s[j] == 'N')) % MOD;
		}
		h1[i] = hash1;
		h2[i] = hash2;
		add(hash1, hash2);
	}
	for (int i = 1; i <= n; i++)
		if (query(h1[i], h2[i]) == q)
		{
			hash1 = hash2 = 0;
			for (int j = 0; j < m; j++)
			{
				hash1 = (hash1 * seed + (a[i].s[j] == 'Y')) % mod;
				hash2 = (hash2 * SEED + (a[i].s[j] == 'Y')) % MOD;
			}
			if (query(hash1, hash2) == p)
			{
				ans = i;
				break;
			}
		}
	if (ans != -1)
	{
		for (int i = 0; i < m; i++)
		{
			if (a[ans].s[i] == 'Y') putchar('N');
			else putchar('Y');
		}
	}
	else puts("-1");
	return ;
}

inline void normal()
{
	int hash1, hash2, hash3, hash4;
	for (int i = 1; i <= n; i++)
	{
		hash1 = hash2 = hash3 = hash4 = 0;
		for (int j = 0; j < m; j++)
		{
			hash1 = (hash1 * seed + (a[i].s[j] == 'N')) % mod;
			hash2 = (hash2 * SEED + (a[i].s[j] == 'N')) % MOD;
			hash3 = (hash3 * seed + (a[i].s[j] == 'Y')) % mod;
			hash4 = (hash4 * SEED + (a[i].s[j] == 'Y')) % MOD;
		}
		add(hash1, hash2);
		add(hash3, hash4);
	}
	for (int i = 0; i < m; i++) nowans[i] = 'N';
	bool flag;
	do
	{
		hash1 = hash2 = 0;
		for (int j = 0; j < m; j++)
		{
			hash1 = (hash1 * seed + (nowans[j] == 'N')) % mod;
			hash2 = (hash2 * SEED + (nowans[j] == 'N')) % MOD;
		}
		if (!query(hash1, hash2))
		{
			flag = true;
			break;
		}
		for (int j = m - 1; ~j; j--)
		{
			if (nowans[j] == 'Y') nowans[j] = 'N';
			else
			{
				nowans[j] = 'Y';
				flag = true;
				break;
			}
		}
	}
	while (flag);
	if (flag) puts(nowans);
	else puts("-1");
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d %d %d %d", &n, &m, &p, &q);
	for (int i = 1; i <= n; i++) scanf("%s", a[i].s);
	sort(a + 1, a + n + 1);
	if (p) special_1();
	else if (q) special_2();
	else normal();
	return 0;
}
