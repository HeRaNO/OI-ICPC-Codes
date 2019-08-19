#include <bits/stdc++.h>
using namespace std;

int T,n,s,f[205],t[105],w[105];

int main()
{
	scanf("%d",&T);
	for (int kas=1;kas<=T;kas++)
	{
		memset(f,0,sizeof f);s=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d %d",&t[i],&w[i]),s+=t[i];
		for (int i=1;i<=n;i++)
			for (int j=s;j>=t[i]+w[i];j--)
				f[j]=max(f[j],f[j-t[i]-w[i]]+t[i]);
		printf("%d\n",s-f[s]);
	}
	return 0;
}