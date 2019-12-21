#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,t;
char s[MAXN];

int main()
{
	scanf("%d%d",&n,&t);
	scanf("%s",s+1);int i=1;
	while (s[i]!='.') ++i;++i;
	while (i<=n&&s[i]<'5') ++i;
	if (i==n+1) return puts(s+1),0;--i;
	for (;t;--t,--i)
	{
		if (s[i]!='.') ++s[i];
		else
		{
			--i;s[i+1]='\0';
			while (i&&s[i]=='9') s[i--]='0';
			if (!i) putchar('1');
			else ++s[i];
			break;
		}
		s[i+1]='\0';
		if (s[i]<'5') break;
	}
	puts(s+1);
	return 0;
}