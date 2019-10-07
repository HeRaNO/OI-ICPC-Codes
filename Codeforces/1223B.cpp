#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,c;
char a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		c=0;scanf("%s",a);n=strlen(a);bool f=false;
		for (int i=0;i<n;i++) c|=(1<<(a[i]-'a'));
		scanf("%s",a);
		for (int i=0;i<n&&!f;i++) if (c&(1<<(a[i]-'a'))) f=true;
		puts(f?"Yes":"No");
	}
	return 0;
}