#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,ta,tb,tc,td,cas,now;
pair <int,int> a[MAXN],b[MAXN],c[MAXN],d[MAXN];
char o[10];

int main()
{
	while (~scanf("%d",&T)&&T)
	{
		ta=0;tb=0;tc=0;td=0;now=0;
		printf("Case #%d:\n",++cas);
		while (T--)
		{
			scanf("%s",o);
			int l=strlen(o);
			if (l==3)
			{
				scanf("%s",o);
				if (o[0]=='A')
				{
					if (!ta) printf("%d\n",d[td--].first);
					else printf("%d\n",a[ta--].first);
				}
				else
				{
					if (!tb) printf("%d\n",d[td--].first);
					else printf("%d\n",b[tb--].first);
				}
			}
			else if (l==4)
			{
				int x;
				scanf("%s %d",o,&x);
				if (o[0]=='A') a[++ta]=make_pair(x,++now);
				else b[++tb]=make_pair(x,++now);
			}
			else
			{
				scanf("%s",o);scanf("%s",o);
				int i=1,j=1;tc=0;
				while (i<=ta&&j<=tb)
				{
					if (a[i].second<b[j].second) c[++tc]=a[i++];
					else c[++tc]=b[j++];
				}
				while (i<=ta) c[++tc]=a[i++];
				while (j<=tb) c[++tc]=b[j++];
				for (int i=1;i<=tc;i++) d[++td]=c[i];
				ta=0;tb=0;
			}
		}
	}
	return 0;
}