#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

char s[MAXN],t[MAXN];
int nxt[MAXN],n,m;
vector <int> ans;

inline void GetNext(char S[])
{
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i != m)
	{
		if (!~j || S[i] == S[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

inline void KMP(char S[], char T[])
{
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (!~j || S[i] == T[j])
		{
			++i; ++j;
			if (j == m)
			{
				ans.push_back(i - m + 1);
				j = nxt[j];
			}
		}
		else j = nxt[j];
	}
	return ;
}

int main()
{
	scanf("%s",s);n=strlen(s);
	scanf("%s",t);m=strlen(t);
	GetNext(t);
	KMP(s,t);
	for (int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
	return 0;
}