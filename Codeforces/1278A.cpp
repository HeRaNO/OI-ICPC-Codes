#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,m,cnt[26],a[26];
char p[MAXN],h[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(cnt,0,sizeof cnt);
		scanf("%s",p);scanf("%s",h);
		n=strlen(p);m=strlen(h);
		if (n>m){puts("NO");continue;}
		for (int i=0;i<n;i++) ++cnt[p[i]-'a'];
		bool ok=false;
		for (int i=0;i<=m-n&&!ok;i++)
		{
			memset(a,0,sizeof a);
			for (int j=0;j<n;j++) ++a[h[i+j]-'a'];
			bool f=false;
			for (int j=0;j<26&&!f;j++) if (cnt[j]!=a[j]) f=true;
			if (!f) ok=true;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}