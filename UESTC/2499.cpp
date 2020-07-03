#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;

int T,prime[MAXN],tot,pfcnt;
bool not_prime[MAXN];
long long pf[MAXN],n,ans;
vector <long long> f;

inline void LinearShaker(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	return ;
}

inline int pfact(long long n)
{
	pfcnt=0;int cnt=0;
	for (int i=1;1LL*prime[i]*prime[i]<=n;i++)
	{
		if (n%prime[i]) continue;++cnt;
		while (!(n%prime[i])) pf[++pfcnt]=prime[i],n/=prime[i];
	}
	if (n!=1){pf[++pfcnt]=n;++cnt;}
	return cnt;
}

inline bool fact(long long n)
{
	int t=pfact(n);
	if (t<=2)
	{
		int cnt=0;
		for (int i=1;i<=pfcnt&&pf[i]==2;i++) ++cnt;
		if (cnt==1||cnt==pfcnt) return false;
	}
	f.clear();
	f.push_back(1);int lst=1;long long lstpri=1,now;
	for (int i=1;i<=pfcnt;i++)
	{
		if (pf[i]==lstpri) now*=lstpri;
		else now=pf[i],lst=f.size();
		for (int j=0;j<lst;j++) f.push_back(now*f[j]);
		lstpri=pf[i];
	}
	return true;
}

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if (!b){x=1;y=0;return a;}
	long long t=exgcd(b,a%b,y,x);y-=x*(a/b);
	return t;
}

int main()
{
	LinearShaker(2000000);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);ans=n<<1;
		if (!fact(n<<1))
		{
			if (pf[pfcnt]==2) printf("%lld\n",(n<<1)-1);
			else printf("%lld\n",n-1);
			continue;
		}
		n<<=1;
		for (auto i:f)
		{
			if (i==1) continue;
			long long j=n/i,x,y;
			if (i>j) continue;
			if (exgcd(i,j,x,y)==1) ans=min(ans,min(abs(x*i),abs(y*j)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}