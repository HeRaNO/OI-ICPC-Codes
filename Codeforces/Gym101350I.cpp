#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int T,n,p[MAXN<<1];
char s[MAXN],t[MAXN<<1],q[MAXN];

inline bool f(char a)
{
	if (a=='#'||a=='$') return true;
	if (a=='A') return true;if (a=='H') return true;if (a=='I') return true;
	if (a=='M') return true;if (a=='O') return true;if (a=='T') return true;
	if (a=='U') return true;if (a=='V') return true;if (a=='W') return true;
	if (a=='X') return true;if (a=='Y') return true;
	return false;
}

inline void Build(char S[], char T[])
{
	int Slen = strlen(S + 1);
	T[0] = '$';
	T[1] = '#';
	for (int i = 1; i <= Slen; i++) T[i << 1] = S[i], T[i << 1 | 1] = '#';
	return ;
}

inline int Manacher(char S[])
{
	int Slen = strlen(S + 1), mx = 0, res = 0, id = 0;
	memset(p, 0, sizeof p);
	for (int i = 1; i <= Slen; i++)
	{
		if (mx > i) p[i] = min(p[(id << 1) - i], mx - i);
		else p[i] = 1;
		while (S[i + p[i]] == S[i - p[i]] && f(S[i + p[i]]) && f(S[i - p[i]])) p[i]++;
		if (mx < i + p[i]) mx = i + p[i], id = i;
	}
	for (int i = 1; i <= Slen; i++) res = max(res, p[i]);
	return res - 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",q);
		n=strlen(q);int ans=0,l=0;
		for (int i=0;i<n;i++)
		{
			if (f(q[i])) s[++l]=q[i];
			else
			{
				Build(s,t);ans=max(ans,Manacher(t));
				memset(s,0,sizeof s);memset(t,0,sizeof t);
				l=0;
			}
		}
		if (l){Build(s,t),ans=max(ans,Manacher(t));}
		printf("%d\n",ans);
		memset(s,0,sizeof s);memset(t,0,sizeof t);
	}
	return 0;
}