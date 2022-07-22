#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,q,a[MAXN];
pair<int,int> pre[MAXN],suf[MAXN];

pair<int,int> getAns(pair<int,int> a,pair<int,int> b)
{
	int am,as,bm,bs;
	tie(am,as)=a;tie(bm,bs)=b;
	if (am<bm) return {am,min(as,bm)};
	if (bm<am) return {bm,min(bs,am)};
	return {am,min(as,bs)};
}

int main()
{
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	pre[0]=suf[n+1]={n,n+1};
	for (int i=1;i<=n;i++) pre[i]=getAns(pre[i-1],{a[i],n+2});
	for (int i=n;i;i--) suf[i]=getAns(suf[i+1],{a[i],n+2});
	while (q--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",getAns(pre[l-1],suf[r+1]).second);
	}
	return 0;
}