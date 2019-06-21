#include <bits/stdc++.h>
#define MAXN 10000010
using namespace std;

char s[MAXN],t[MAXN<<1];
int p[MAXN<<1],n;

inline void Build(char S[], char T[])
{
	int Slen = n;
	T[0] = '$';
	T[1] = '#';
	for (int i = 1; i <= Slen; i++) T[i << 1] = S[i], T[(i << 1) + 1] = '#';
	return ;
}

inline int Manacher(char S[])
{
	int Slen = n << 1, mx = 0, res = 0, id = 0;
	for (int i = 1; i <= Slen; i++)
	{
		if (mx > i) p[i] = min(p[(id << 1) - i], mx - i);
		else p[i] = 1;
		while (S[i + p[i]] == S[i - p[i]]) p[i]++;
		if (mx < i + p[i]) mx = i + p[i], id = i;
	}
	for (int i = 1; i <= Slen; i++) if (S[i] == '#') res = max(res, p[i]);
	return res - 1;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	Build(s,t);
	printf("%d\n",Manacher(t));
	return 0;
}
