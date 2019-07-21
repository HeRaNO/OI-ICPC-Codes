#include <bits/stdc++.h>

int T,n,m,u,v;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);bool f=false;
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d",&u,&v);
			if (u==1&&v==n) f=true;
		}
		puts(f?"Jorah Mormont":"Khal Drogo");
	}
	return 0;
}