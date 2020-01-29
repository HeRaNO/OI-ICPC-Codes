#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m,cnt[26],las[26],son[MAXN][26],ans;
char s[MAXN],t[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=0;
		memset(cnt,0,sizeof cnt);memset(las,-1,sizeof las);
		scanf("%s",s);n=strlen(s);
		scanf("%s",t);m=strlen(t);bool f=false;
		for (int i=0;i<n;i++) ++cnt[s[i]-'a'];
		for (int i=0;i<m&&!f;i++)
			if (!cnt[t[i]-'a'])
				puts("-1"),f=true;
		if (f) continue;
		for (int i=n;~i;i--)
		{
			for (int j=0;j<26;j++) son[i][j]=las[j];
			if (i) las[s[i-1]-'a']=i;
		}
		for (int i=0,p=0;i<m;)
		{
			while (~son[p][t[i]-'a']&&i<m)
			{
				p=son[p][t[i]-'a'];++i;
			}
			++ans;p=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}