#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const int d[3]={-1,0,1};

int n,a[MAXN],b[MAXN],ans=~(1<<31);

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
		{
			int now=0;
			int nd=a[2]+d[i]-a[1]-d[j];
			b[2]=a[2]+d[i];b[1]=a[1]+d[j];
			if (d[i]) ++now;if (d[j]) ++now;
			for (int i=3;i<=n;i++)
			{
				int tar=b[i-1]+nd;
				if (abs(a[i]-tar)>1){now=~(1<<31);break;}
				if (abs(a[i]-tar)==1) ++now;
				b[i]=tar;
			}
			ans=min(ans,now);
		}
	printf("%d\n",ans==~(1<<31)?-1:ans);
	return 0;
}