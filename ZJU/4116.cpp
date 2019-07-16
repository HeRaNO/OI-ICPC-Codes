#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n,m,k,u,v;
char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&k);
		scanf("%s",s);
		scanf("%d %d",&n,&m);
		for (int i=1;i<=m;i++) scanf("%d %d",&u,&v);
		if (s[(m-n+1+k)%k]=='1') puts("2");
		else puts("1");
	}
	return 0;
}