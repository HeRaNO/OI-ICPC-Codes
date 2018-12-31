#include <bits/stdc++.h>
#define MAXN 210
#define MAXM 20010
using namespace std;

int a[MAXN], seq[MAXN], cnt;
int n, m, S, T, ans, uans;
int ed[MAXM][2], father[MAXN];

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

inline void Merge(int x, int y)
{
	father[getfather(x)] = getfather(y);
	return ;
}

int main(int argc, char const *argv[])
{
	ifstream fin(argv[1]), fout(argv[2]), fuser(argv[3]);
	fin >> n >> m;
	fin >> S >> T;
	for (int i = 1; i <= n; i++) fin >> a[i], father[i] = i;
	for (int i = 1; i <= m; i++) fin >> ed[i][0] >> ed[i][1];
	while (fout >> seq[++cnt]);
	for (int i = 1; i <= cnt; i++) ans += a[seq[i]];
	cnt = 0;
	while (fuser >> seq[++cnt]);
	for (int i = 1; i <= cnt; i++) uans += a[seq[i]];
	if (uans != ans)
	{
		puts("WA!");
		return 1;
	}
	for (int i = 1; i <= m; i++)
	{
		bool ban = false;
		for (int j = 1; j <= cnt && !ban; j++)
			if (ed[i][0] == seq[j] || ed[i][1] == seq[j]) ban = true;
		if (!ban) Merge(ed[i][0], ed[i][1]);
	}
	if (getfather(S) == getfather(T))
	{
		puts("WA!");
		return 1;
	}
	else puts("AC!");
	return 0;
}