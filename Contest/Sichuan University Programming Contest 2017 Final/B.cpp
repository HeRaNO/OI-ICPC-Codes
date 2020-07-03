#include <bits/stdc++.h>
#define MAXN 1005
#define MAXL 1000005
using namespace std;

mt19937_64 rand_num(chrono::system_clock::now().time_since_epoch().count());

int n,m,q,x,T;
long long a[MAXL],s[MAXL],b[MAXN][MAXN];

int main()
{
	n=1000;m=1000;
	for (int i=1;i<=n*m;i++) a[i]=rand_num();
	for (int i=1;i<=n*m;i++) s[i]=s[i-1]^a[i];
	while (scanf("%d %d",&n,&m)==2)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&x);
				b[i][j]=b[i][j-1]^a[x];
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				b[i][j]^=b[i-1][j];
		scanf("%d",&q);
		while (q--)
		{
			int u,v,x,y;
			scanf("%d %d %d %d",&u,&v,&x,&y);
			long long t=b[x][y]^b[u-1][y]^b[x][v-1]^b[u-1][v-1];
			if (t==s[(x-u+1)*(y-v+1)]) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}