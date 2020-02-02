#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

char s[MAXN];
int T,n,l,r,cnt[MAXN][26];

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=n;i++)
		for (int j=0;j<26;j++)
			cnt[i][j]=cnt[i-1][j]+(s[i]-'a'==j);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&l,&r);
		if (l==r) puts("Yes");
		else
		{
			int t=0;
			for (int i=0;i<26;i++) t+=((cnt[r][i]-cnt[l-1][i])>0);
			if (t>=3){puts("Yes");continue;}
			if (s[l]!=s[r]){puts("Yes");continue;}
			puts("No");
		}
	}
	return 0;
}