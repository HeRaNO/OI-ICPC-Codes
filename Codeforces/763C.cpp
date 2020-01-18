#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int m,n,a[MAXN],d,x=-1;
set <int> s;

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=m) if (b&1) (r*=a)%=m;
	return r;
}

inline int getK(int d)
{
	int k=0;
	for (int i=1;i<=n;i++)
		for (int j=-d;j<=d;j+=d+d)
		{
			int y=(a[i]+j+m)%m;
			if (a[i]<=y&&s.find(y)!=s.end()) ++k;
		}
	return k;
}

inline void solve()
{
	if (n<=1)
	{
		x=!n?1:a[1];d=1;
		return ;
	}
	int k=n-getK(a[2]-a[1]);
	d=1LL*fpow(k,m-2)*(a[2]-a[1])%m;
	int y=a[1],cnt=0;
	while (true)
	{
		if (s.find(y)==s.end()) break;
		y+=d;if (y>=m) y-=m;++cnt;
	}
	y=a[1];
	while (true)
	{
		if (s.find(y)==s.end()) break;
		x=y;y-=d;if (y<0) y+=m;++cnt;
	}
	if (cnt!=n+1){x=-1;d=-1;}
	return ;
}

int main()
{
	scanf("%d %d",&m,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s.insert(a[i]);
	if (n==1) return printf("%d %d\n",a[1],m-1),0;
	sort(a+1,a+n+1);
	if (m<=(n<<1))
	{
		for (int i=0;i<m;i++)
			if (s.find(i)==s.end())
				a[++a[0]]=i;
		n=m-n;s.clear();
		for (int i=1;i<=n;i++) s.insert(a[i]);
		solve();
		if (~x) (x+=1LL*n*d%m)%=m;
	}
	else solve();
	if (~x) return printf("%d %d\n",x,d),0;
	puts("-1");
	return 0;
}