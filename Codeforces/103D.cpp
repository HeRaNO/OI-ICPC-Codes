#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

struct D
{
	int a,b,c;
	bool operator < (const D &a)const{
		return b<a.b;
	}
};

D b[MAXN];
int n,m,T,a[MAXN];
long long c[MAXN],ans[MAXN];

inline void calc(int x)
{
	for (int i=n;i;i--)
	{
		c[i]=a[i];
		if (i+x<=n) c[i]+=c[i+x];
	}
	return ;
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
	read(n);for (int i=1;i<=n;i++) read(a[i]);m=(int)sqrt(n);
	read(T);for (int i=1;i<=T;i++) read(b[i].a),read(b[i].b),b[i].c=i;
	sort(b+1,b+T+1);int cur=1;
	for (;b[cur].b<=m&&cur<=T;cur++)
	{
		if (b[cur].b!=b[cur-1].b) calc(b[cur].b);
		ans[b[cur].c]=c[b[cur].a];
	}
	for (long long res=0;cur<=T;cur++,res=0)
	{
		for (int j=b[cur].a;j<=n;j+=b[cur].b) res+=a[j];
		ans[b[cur].c]=res;
	}
	for (int i=1;i<=T;i++) printf("%lld\n",ans[i]);
	return 0;
}