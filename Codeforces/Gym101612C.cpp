#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const char v[]="aeiouwy";
const char c[]="bcdfghjklmnpqrstvxz";

int n,f[26],cnt[26][26],ans,res;
char s[MAXN],g[27];

inline bool vowel(char a)
{
	for (int i=0;i<7;i++) if (v[i]==a) return true;
	return false;
}

int main()
{
	freopen("consonant.in","r",stdin);
	freopen("consonant.out","w",stdout);
	for (int i=0;i<19;i++) f[c[i]-'a']=i;
	for (int i=0;i<26;i++) g[i]=i+'a';
	scanf("%s",s);n=strlen(s);
	for (int i=1;i<n;i++)
	{
		if (vowel(s[i-1])||vowel(s[i])) continue;
		++cnt[f[s[i-1]-'a']][f[s[i]-'a']];
	}
	for (int i=0;i<(1<<19);i++)
	{
		int cc=0;
		for (int p=0;p<19;p++)
			for (int q=0;q<19;q++)
				if (((i>>p)&1)^((i>>q)&1))
					cc+=cnt[p][q];
		if (cc>res)
		{
			res=cc;ans=i;
		}
	}
	for (int i=0;i<19;i++)
		if (ans&(1<<i))
			g[c[i]-'a']-=32;
	for (int i=0;i<n;i++) putchar(g[s[i]-'a']);putchar('\n');
	return 0;
}