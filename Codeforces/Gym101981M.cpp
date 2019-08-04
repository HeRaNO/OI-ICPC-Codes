#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int n,m,exnxt[MAXN],p[MAXN<<1];
char s[MAXN],t[MAXN],r[MAXN<<1];
long long a[MAXN],ext[MAXN],ans;

inline void GetExtendNext(char S[])
{
	int a = 0, Slen = m;
	exnxt[0] = Slen;
	while (a < Slen && S[a] == S[a + 1]) a++;
	exnxt[1] = a;
	a = 1;
	for (int i = 2; i < Slen; i++)
	{
		int p = a + exnxt[a] - 1, l = exnxt[i - a];
		if (i - 1 + l >= p)
		{
			int j = (p - i + 1) > 0 ? p - i + 1 : 0;
			while (i + j < Slen && S[i + j] == S[j]) j++;
			exnxt[i] = j;
			a = i;
		}
		else exnxt[i] = l;
	}
	return ;
}

inline void GetExtend(char S[], char T[])
{
	int a = 0;
	GetExtendNext(T);
	int Slen = n, Tlen = m;
	int Minlen = min(Slen, Tlen);
	while (a < Minlen && S[a] == T[a]) a++;
	ext[0] = a;
	a = 0;
	for (int i = 1; i < Slen; i++)
	{
		int p = a + ext[a] - 1, l = exnxt[i - a];
		if (i - 1 + l >= p)
		{
			int j = (p - i + 1) > 0 ? p - i + 1 : 0;
			while (i + j < Slen && j < Tlen && S[i + j] == T[j]) j++;
			ext[i] = j;
			a = i;
		}
		else ext[i] = l;
	}
	return ;
}

inline void Build(char S[], char T[])
{
	int Slen = strlen(S + 1);
	T[0] = '$';
	T[1] = '#';
	for (int i = 1; i <= Slen; i++) T[i << 1] = S[i], T[(i << 1) + 1] = '#';
	return ;
}

inline void Manacher(char S[])
{
	int Slen = n << 1, mx = 0, res = 0, id = 0;
	for (int i = 1; i <= Slen; i++)
	{
		if (mx > i) p[i] = min(p[(id << 1) - i], mx - i);
		else p[i] = 1;
		while (S[i + p[i]] == S[i - p[i]]) p[i]++;
		if (mx < i + p[i]) mx = i + p[i], id = i;
	}
	return ;
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t);m=strlen(t);
	Build(s,r);
	Manacher(r);
	for (int i=n<<1;i>=2;i--) ++a[i>>1],--a[(i>>1)-(p[i]>>1)];
	for (int i=n;i;i--) a[i]+=a[i+1];
	for (int i=0;i<n;i++) r[i]=s[n-i];r[n]=0;
	GetExtend(r,t);
	for (int i=1;i<=n;i++) ans+=ext[n-i+1]*a[i];
	printf("%lld\n",ans);
	return 0;
}