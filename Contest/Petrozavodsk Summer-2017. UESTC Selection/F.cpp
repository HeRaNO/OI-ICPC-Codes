#include <bits/stdc++.h>
using namespace std;

int T,p,q;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&p,&q);
		if (p<=q) printf("%d\n",q-p);
		else
		{
			int now=0,las=0,ans=~(1<<31),d=p-q;
			for (int i=30;i;i--)
			{
				int c=(1<<i)-1,cn=(d-1)/c;
				now+=cn*i;las+=cn;d-=c*cn;
				ans=min(ans,now+i+max(las,c-d));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}