#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,m,a,b,r,x[MAXN],y[MAXN];
bool v[10001][10001];

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);int ans=n;
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	read(m);
	for (int i=1;i<=m;i++)
	{
		read(a);read(b);read(r);
		for (int nx=max(a-r,0),p=min(10000,a+r);nx<=p;nx++)
			for (int ny=max(b-r,0),q=min(10000,b+r);ny<=q;ny++)
				if ((nx-a)*(nx-a)+(ny-b)*(ny-b)<=r*r) v[nx][ny]=true;
	}
	for (int i=1;i<=n;i++) if (v[x[i]][y[i]]) --ans;
	printf("%d\n",ans);
	return 0;
}