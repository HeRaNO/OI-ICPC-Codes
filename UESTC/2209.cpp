#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

char s[MAXN];
int nxt[MAXN],n;
bool f=true;

inline void GetNext(char S[])
{
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i != n)
	{
		if (!~j || S[i] == S[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

int main()
{
	scanf("%s",s);n=strlen(s);GetNext(s);
	int r=nxt[n];
	while (~r)
	{
		if (f){printf("%d",n-r);f=false;}
		else printf(" %d",n-r);
		r=nxt[r];
	}
	putchar('\n');
	return 0;
}