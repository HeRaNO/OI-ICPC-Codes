#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;

int a[MAXN],l[MAXN],r[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		a[l[i]]++;
		a[r[i]]--;
	}
	int maxn=0;
	for(int i=1;i<=MAXN-5;i++)
	{
		a[i]+=a[i-1];
		maxn=max(maxn,a[i]);
	}
	int ll=MAXN,rr=0;
	for(int i=1;i<=MAXN-5;i++)
		if(a[i]==maxn)
		{
			ll=min(ll,i);
			rr=max(rr,i);
		}
	for(int i=1;i<=n;i++)
	{
		if(l[i]<=ll&&r[i]>rr)
		{
			maxn--;
			break;
		}
	}
	printf("%d",maxn);
	return 0;
}
