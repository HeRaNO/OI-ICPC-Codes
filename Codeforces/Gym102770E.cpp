#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

long long _i2[MAXN],sum[20][MAXN],s[MAXN];
int T,n,m,l,r,k,cnt[20][MAXN],tr[20][MAXN],a[MAXN];

void init(int n)
{
	for (int i=1;i<=n;i++) _i2[i]=1LL*i*i;
	for (int i=1;i<=n;i++) _i2[i]+=_i2[i-1];
	return ;
}

void Build(int u,int l,int r)
{
	if (l==r) return ;
	sum[u][0]=cnt[u][0]=0;
	int same=0,m=l+r>>1;
	for (int i=m;i>=l;i--)
		if (a[i]==a[m]) ++same;
		else break;
	int li=l,ri=m+1,ccnt=0;
	for (int i=l;i<=r;i++)
	{
		sum[u][i]=sum[u][i-1];
		if (tr[u][i]<a[m])
		{
			tr[u+1][li++]=tr[u][i];
			sum[u][i]+=tr[u][i];
			++ccnt;
		}
		else if (tr[u][i]==a[m]&&same)
		{
			--same;++ccnt;
			tr[u+1][li++]=tr[u][i];
			sum[u][i]+=tr[u][i];
		}
		else tr[u+1][ri++]=tr[u][i];
		cnt[u][i]=ccnt;
	}
	Build(u+1,l,m);Build(u+1,m+1,r);
	return ;
}

long long query(int u,int l,int r,int k,int pl,int pr)
{
	if (pl==pr) return tr[u][l];
	int lft=0,m=pl+pr>>1,sl=0;
	if (l==pl) sl=cnt[u][r];
	else
	{
		sl=cnt[u][r]-cnt[u][l-1];
		lft=cnt[u][l-1];
	}
	if (sl>=k)
	{
		int nl=pl+lft;
		int nr=pl+lft+sl-1;
		return query(u+1,nl,nr,k,pl,m);
	}
	else
	{
		int nl=m+l-pl+1-lft;
		int nr=m+r-pl+1-lft-sl;
		return sum[u][r]-sum[u][l-1]+query(u+1,nl,nr,k-sl,m+1,pr);
	}
}

void Solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tr[0][i]=a[i];s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	Build(0,1,n);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d %d %d",&l,&r,&k);
		long long ans=_i2[r-l+1],t;
		if (k==r-l+1) t=0;
		else t=query(0,l,r,r-l+1-k,1,n);
		t=s[r]-s[l-1]-t;
		printf("%lld\n",ans+t);
	}
	return ;
}

int main()
{
	init(100000);
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}