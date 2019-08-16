#include <bits/stdc++.h>
using namespace std;

int a[11][11],n,ans,kas;

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	while (true)
	{
		read(n);ans=0;if (!n) break;
		printf("Case #%d:", ++kas);
		if (n==1)
		{
			read(a[1][1]);
			printf("%d\n",a[1][1]);
			continue;
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=i;j++)
				read(a[i][j]);
		for (int i=1;i<n;i++) ans+=a[i][1];
		for (int i=1;i<n;i++) ans+=a[n][i];
		for (int i=n;i>1;i--) ans+=a[i][i];
		printf("%d\n", ans);
	}
	return 0;
}