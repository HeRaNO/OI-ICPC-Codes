#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,f[MAXN];
char s[100];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if (s[0]=='T') f[i]=1;
		else f[i]=0;
	}
	int ans=f[n];
	for (int i=n-1;i;i--)
	{
		if (ans) ans=f[i];
		else ans=!f[i];
	}
	if (ans) puts("TRUTH");
	else puts("LIE");
	return 0;
}