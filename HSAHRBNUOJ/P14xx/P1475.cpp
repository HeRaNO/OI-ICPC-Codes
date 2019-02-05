#include <queue>
#include <cmath>
#include <cstdio>
#define MAXN 2048
using namespace std;

long long l,r,p[MAXN],b[MAXN],ans;
int n,m;bool a[MAXN];
queue <long long> q;

inline long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}

void BFS()
{
	q.push(3);q.push(8);
	while (!q.empty())
	{
		long long x=q.front();q.pop();
		if (x>r) continue;
		p[++n]=x;q.push(x*10LL+3LL);q.push(x*10LL+8LL);
	}
	return ;
}

void dfs(int x,int cnt,long long lcm)
{
	if (x>m)
	{
		if (!cnt) return ;
		if (cnt&1) ans+=r/lcm-(l-1)/lcm;
		else ans-=r/lcm-(l-1)/lcm;
		return ;
	}
	dfs(x+1,cnt,lcm);long long t=lcm/gcd(p[x],lcm);
	if (log(p[x])+log(t)<=log(r)) dfs(x+1,cnt+1,t*p[x]);
	return ;
}

int main()
{
	scanf("%lld %lld",&l,&r);BFS();
	for (int i=1;i<=n;i++)
		if (!a[i])
		{
			b[++m]=p[i];
			for (int j=i+1;j<=n;j++)
				if (!(p[j]%p[i])) a[j]=true;
		}
	for (int i=1;i<=m;i++) p[m-i+1]=b[i];
	dfs(1,0,1);
	printf("%lld\n",ans);
	return 0;
}
