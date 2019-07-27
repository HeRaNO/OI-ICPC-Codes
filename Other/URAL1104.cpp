#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

char s[MAXN];
int n,mx;

inline int f(char s)
{
	if (s>='A') return s-'A'+10;
	return s-'0';
}

int main()
{
	scanf("%s",s);n=strlen(s);
	for (int i=0;i<n;i++) mx=max(mx,f(s[i]));
	for (int i=mx+1;i<=36;i++)
	{
		if (i<=1) continue;
		int x=0;
		for (int j=0;j<n;j++) x=(x*i+f(s[j]))%(i-1);
		if (!x) return printf("%d\n",i),0;
	}
	puts("No solution.");
	return 0;
}