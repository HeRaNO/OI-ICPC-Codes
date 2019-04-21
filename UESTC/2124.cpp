#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,T,o,x,y,l,v,f[MAXN],fx,fy;
long long ans[MAXN],a[MAXN];

inline int getf(int x)
{
	if (x==f[x]) return x;
	int t=f[x];f[x]=getf(f[x]);
	ans[x]+=ans[t];
	return f[x];
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(T);
	for (int i=1,x;i<=n;i++)
	{
		read(x);f[i]=i;ans[i]=x;a[i]=x;
	}
	while (T--)
	{
		read(o);
		if (o==1)
		{
			read(x);read(y);read(l);
			fx=getf(x);fy=getf(y);
			if (fx!=fy)
			{
				f[fx]=fy;ans[fy]+=ans[fx];
			}
		}
		else if (o==2)
		{
			read(x);read(v);fx=getf(x);
			ans[fx]+=v;a[x]+=v;
		}
		else
		{
			read(x);fx=getf(x);
			printf("%lld\n",ans[fx]-a[x]);
		}
	}
	return 0;
}