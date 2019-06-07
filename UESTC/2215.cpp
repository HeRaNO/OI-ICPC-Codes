#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 200005
using namespace std;

struct link
{
	int x,y;long long z;bool f,g;
	bool operator < (const link &a)const{
		return z<a.z;
	}
};

link e[MAXM];
int n,m,x,f[MAXN],fx,fy,cnt;
long long ans,mx;

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++) read(e[i].x),read(e[i].y),read(x),e[i].z=x;
	sort(e+1,e+m+1);
	for (int i=1;i<=m;i++)
	{
		fx=getf(e[i].x);fy=getf(e[i].y);
		if (fx!=fy)
		{
			f[fy]=fx;ans+=e[i].z;++cnt;e[i].f=true;
			if (cnt==n-1)
			{
				printf("%lld ",ans-e[i].z);mx=e[i].z;break;
			}
		}
	}
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
		if (e[i].f&&e[i].z<mx)
		{
			e[i].g=true;
			fx=getf(e[i].x);fy=getf(e[i].y);
			if (fx!=fy) f[fy]=fx;
		}
	cnt=0;
	for (int i=1;i<=m;i++)
		if (!e[i].g)
		{
			fx=getf(e[i].x);fy=getf(e[i].y);
			if (fx!=fy) ++cnt;
		}
	printf("%d\n",cnt);
	return 0;
}