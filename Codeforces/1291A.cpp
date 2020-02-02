#include <bits/stdc++.h>
#define MAXN 3005
using namespace std;

int n,T;
char s[MAXN],a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);scanf("%s",s);int cnt=0;
		for (int i=0;i<n;i++) cnt+=(s[i]&1);
		if (cnt<2) puts("-1");
		else
		{
			int o=0;
			for (int i=0;i<n;i++)
				if (s[i]&1)
				{
					putchar(s[i]);++o;
					if (o==2) break;
				}
			putchar('\n');
		}
	}
	return 0;
}