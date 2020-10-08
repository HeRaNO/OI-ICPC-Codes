#include <bits/stdc++.h>
#define MAXB 450
#define MAXN 200005
using namespace std;

int n,Q,o,A,B,c,ans[MAXB][MAXB];
int a[MAXN];

int main()
{
	scanf("%d %d",&n,&Q);
	while (Q--)
	{
		scanf("%d",&o);
		if (o==1)
		{
			scanf("%d %d %d",&A,&B,&c);
			if (B<=448) ans[B][A]+=c;
			else
			{
				for (int i=A;i<=n;i+=B) a[i]+=c;
			}
		}
		else
		{
			scanf("%d",&A);int res=0;
			for (int i=1;i<=448;i++) res+=ans[i][A%i];
			printf("%d\n",a[A]+res);
		}
	}
	return 0;
}