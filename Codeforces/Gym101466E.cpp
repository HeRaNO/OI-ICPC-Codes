#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

char a[MAXN],b[MAXN],s[MAXN];
int n,k,ans,l,r,nxt[MAXN];

inline void GetNext(char S[], int len)
{
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i != len)
	{
		if (!~j || S[i] == S[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

inline int KMP(char S[], char T[], int lb, int la)
{
	int ans = 0;
	int i = 0, j = 0;
	while (i < lb && j < la)
	{
		if (!~j || S[i] == T[j])
		{
			++i; ++j;
			if (j == la)
			{
				++ans; j = nxt[j - 1]; --i;
			}
		}
		else j = nxt[j];
	}
	return ans;
}

bool check(int m)
{
	for (int i=0;i<m;i++) s[i]=b[i];
	GetNext(b,m);
	return KMP(a,s,n,m)>=k;
}

int main()
{
	gets(a);
	n=strlen(a);
	gets(b);
	l=0;r=strlen(b);
	scanf("%d",&k);
	while (l<=r)
	{
		int m=l+r>>1;
		if (check(m)){ans=m;l=m+1;}
		else r=m-1;
	}
	if (!ans) return puts("IMPOSSIBLE"),0;
	for (int i=0;i<ans;i++) putchar(b[i]);putchar('\n');
	return 0;
}