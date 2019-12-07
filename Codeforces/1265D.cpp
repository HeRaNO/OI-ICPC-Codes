#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,a[5],b[5],ans[MAXN];

void Setit(int x,int i)
{
	--b[x];ans[i]=x;return ;
}

bool Analyze(int x)
{
	ans[1]=x;
	for (int i=0;i<=3;i++) b[i]=a[i];--b[x];
	for (int i=2;i<=n;i++)
	{
		if (!ans[i-1])
		{
			if (!b[1]) return false;
			Setit(1,i);
		}
		else if (ans[i-1]==1)
		{
			if (!b[0]&&!b[2]) return false;
			if (b[0]) Setit(0,i);
			else Setit(2,i);
		}
		else if (ans[i-1]==2)
		{
			if (!b[1]&&!b[3]) return false;
			if (b[1]) Setit(1,i);
			else Setit(3,i);
		}
		else
		{
			if (!b[2]) return false;
			Setit(2,i);
		}
	}
	return true;
}

int main()
{
	for (int i=0;i<=3;i++) scanf("%d",&a[i]);
	for (int i=0;i<=3;i++) n+=a[i];
	for (int i=0;i<=3;i++)
		if (a[i]&&Analyze(i))
		{
			puts("YES");
			for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
			return 0;
		}
	puts("NO");
	return 0;
}