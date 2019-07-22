#include <bits/stdc++.h>
using namespace std;

int n,cnt[26];
char s[101];

int main()
{
	while (~scanf("%d",&n))
	{
		scanf("%s",s);memset(cnt,0,sizeof cnt);
		if (n<4){puts("0/1");continue;}
		for (int i=0;i<n;i++) ++cnt[s[i]-'a'];
		int p=cnt['a'-'a']*cnt['v'-'a']*cnt['i'-'a']*cnt['n'-'a'];
		if (!p){puts("0/1");continue;}
		int all=n*n*n*n;
		int g=__gcd(p,all);
		printf("%d/%d\n",p/g,all/g);
	}
	return 0;
}