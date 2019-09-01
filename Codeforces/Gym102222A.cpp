#include <bits/stdc++.h>
#define MAXN 5000005
using namespace std;

int n, p, q, m;
unsigned int SA, SB, SC;

unsigned int rng61() {
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA;
	SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}

struct sta
{
	unsigned int sta[MAXN];int tp;
	unsigned int mx[MAXN];int mxtp;
	void push(unsigned int x)
	{
		if (!tp)
		{
			sta[++tp]=x;
			mx[++mxtp]=x;
		}
		else
		{
			sta[++tp]=x;
			unsigned int pp=mx[mxtp];
			mx[++mxtp]=max(pp,x);
		}
	}
	void pop()
	{
		if (tp)
		{
			--tp;--mxtp;
		}
		return ;
	}
	void clear()
	{
		tp=0;mxtp=0;
		return ;
	}
	unsigned int getmx()
	{
		if (!tp) return 0;
		return mx[mxtp];
	}
};

sta a;
int T,cas;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		a.clear();unsigned long long ans=0;
		scanf("%d%d%d%d",&n,&p,&q,&m);
		scanf("%u%u%u",&SA,&SB,&SC);
		for(int i=1;i<=n;i++)
		{
			if(rng61()%(p+q)<p) a.push(rng61()%m+1);
			else a.pop();
			ans^=1LL*i*a.getmx();
		}
		printf("Case #%d: %llu\n",++cas,ans);
	}
	return 0;
}