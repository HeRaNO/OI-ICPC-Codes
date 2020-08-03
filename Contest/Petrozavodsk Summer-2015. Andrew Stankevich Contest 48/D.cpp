#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

int n,m,q,C,A[MAXN],a,b,c,l,r,k;
bitset <1005> f[MAXN][MAXN];

inline void init()
{
	for (int i=1;i<=n;i++)
	{
		f[i][i].reset();
		f[i][i].set(0);f[i][i].set(A[i]);
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<n;j++)
			f[i][j+1]=(f[i][j]<<A[j+1])|f[i][j];
	return ;
}

int main()
{
	freopen("decisions.in","r",stdin);
	freopen("decisions.out","w",stdout);
	while (true)
	{
		scanf("%d",&n);if (!n) break;
		for (int i=1;i<=n;i++) scanf("%d",&A[i]);
		k=0;init();
		scanf("%d",&C);
		scanf("%d",&q);
		while (q--)
		{
			scanf("%d %d %d",&a,&b,&c);
			l=(a+k)%(n-b+1)+1;r=l+b-1;(c+=k)%=(C+1);
			if (f[l][r][c]) putchar('Y'),++k;
			else putchar('N');
		}
		putchar('\n');
	}
	return 0;
}