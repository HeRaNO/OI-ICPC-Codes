#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

int n,cnt[4],all;
char s[MAXN][MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (s[i][j]=='o') ++cnt[(n-i+j)%4],++all;
	all>>=2;
	for (int i=0;i<4;i++)
		if (abs(all-cnt[i])&1) return puts("1"),0;
	puts("0");
	return 0;
}