#include <bits/stdc++.h>
#define MAXN 100005
#define MAXK 18
#define MAXM 100035
using namespace std;

int T,l1,r1,p1,d1,l2,r2,p2,d2,k;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d",&l1,&r1,&p1,&d1);
		scanf("%d %d %d %d",&l2,&r2,&p2,&d2);
		scanf("%d",&k);int ans=0;
		if (p1==l1&&d1==0) d1=1;
		if (p1==r1&&d1==1) d1=0;
		if (p2==l2&&d2==0) d2=1;
		if (p2==r2&&d2==1) d2=0;
		while (k--)
		{
			if (!d1) --p1;
			else ++p1;
			if (!d2) --p2;
			else ++p2;
			if (p1==p2) ++ans;
			if (p1==l1||p1==r1) d1^=1;
			if (p2==l2||p2==r2) d2^=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}