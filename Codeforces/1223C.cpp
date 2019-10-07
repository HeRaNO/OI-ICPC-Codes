#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct C
{
	long long val,id;
};

C q[MAXN];
int T,n,cnt,a,b,c;
long long k,v[MAXN],p[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt=0;memset(v,0,sizeof v);scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&p[i]),p[i]/=100;
		scanf("%d%d",&b,&a);
		for (int i=1;i*a<=n;i++) v[i*a]+=b;
		scanf("%d%d",&c,&a);
		for (int i=1;i*a<=n;i++) v[i*a]+=c;
		for (int i=1;i<=n;i++) if (v[i]) q[++cnt]={v[i],i};
		scanf("%lld",&k);
		sort(p+1,p+n+1,greater<long long>());
		int c1=0,c2=0,c3=0;bool f=false;
		for (int i=1;i<=cnt&&!f;i++)
		{
			if (q[i].val==b+c)
			{
				c3++;
				k-=p[c3]*(b+c-max(b,c));
				k-=p[c1+c2+c3]*min(b,c);
				if (b>c) k-=p[c1+c3]*(b-c);
				else k-=p[c2+c3]*(c-b);
			}
			else if (q[i].val==b)
			{
				c1++;
				if (b>c)
				{
					k-=p[c1+c3]*(b-c);
					k-=p[c1+c2+c3]*c;
				}
				else k-=p[c1+c2+c3]*b;
			}
			else if (q[i].val==c)
			{
				c2++;
				if (c>b)
				{
					k-=p[c2+c3]*(c-b);
					k-=p[c1+c2+c3]*b;
				}
				else k-=p[c1+c2+c3]*c;
			}
			if (k<=0)
			{
				f=true;
				printf("%lld\n",q[i].id);
			}
		}
		if (!f) puts("-1");
	}
	return 0;
}