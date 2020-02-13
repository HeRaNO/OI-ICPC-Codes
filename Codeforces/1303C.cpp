#include <bits/stdc++.h>
using namespace std;

int T,n,pt,l,r;
char s[205],q[100];
bool vis[26];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		pt=27;l=28,r=27;memset(q,0,sizeof q);bool f=false;
		memset(vis,false,sizeof vis);
		scanf("%s",s+1);n=strlen(s+1);
		for (int i=1;i<=n&!f;i++)
		{
			if (!vis[s[i]-'a'])
			{
				if (pt==r) q[r=++pt]=s[i];
				else if (pt==l) q[l=--pt]=s[i];
				else f=true;
				vis[s[i]-'a']=true;
			}
			else
			{
				if (q[pt-1]==s[i]) --pt;
				else if (q[pt+1]==s[i]) ++pt;
				else f=true;
			}
		}
		for (int i=0;i<26;i++) if (!vis[i]) q[++r]=i+'a';
		if (!f){puts("YES");puts(q+l);}
		else puts("NO");
	}
	return 0;
}