#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,o,x,t[MAXN*20][2],id[MAXN*20],top;

inline void add(int x)
{
	int now=0;
	for (int i=20;~i;i--)
	{
		int p=x>>i&1;
		if (!~t[now][p])
		{
			t[top][0]=t[top][1]=-1;
			t[now][p]=top++;
		}
		now=t[now][p];
	}
	id[now]=x;
	return ;
}

inline int query(int x)
{
	int mx=0,now=0;
	for (int i=20;~i;i--)
	{
		int p=x>>i&1;
		if (~t[now][p^1]) now=t[now][p^1];
		else now=t[now][p];
	}
	return id[now];
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
	top=1;t[0][0]=-1;t[0][1]=-1;
	read(n);
	for (int i=1;i<=n;i++) read(x),add(x);
	read(T);
	while (T--)
	{
		read(o);read(x);
		if (!o) add(x);
		else printf("%d\n",query(x));
	}
	return 0;
}