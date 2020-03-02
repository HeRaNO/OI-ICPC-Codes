#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=100050;
int n,m;
ll s[N],s2[N];

struct edge
{
	int id;
	int exist;
	int w;
	bool operator < (const edge &x)const
	{
		return w<x.w||(w==x.w&&exist>x.exist);
	}
}e[N];
struct Answer
{
	int u,v;
}ans[N];
int cnt;
vector <int> pos;
int p;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&e[i].w,&e[i].exist);
		e[i].id=i;
		cnt+=e[i].exist;
	}
	if(cnt!=n-1)return puts("-1"),0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;++i)s2[i]=s2[i-1]+e[i].exist;
	for(int i=1;i<=m;++i)
	{
		if(e[i].exist==0)
		{
			if(2LL*(i-s2[i])>(s2[i]-1)*s2[i])
				return puts("-1"),0;
		}
	}
	bool flag=true;
	int L=1,R=3,now=1;
	for(int i=1;i<=m;++i)
	{
		int id=e[i].id;
		if(e[i].exist==1)
		{
			ans[id].u=now;
			ans[id].v=++now;
		}
		else
		{
			ans[id].u=L;
			ans[id].v=R;
			L++;
			if(L==R-1)L=1,R++;
		}
	}
	for(int i=1;i<=m;++i)
	{
		printf("%d %d\n",ans[i].u,ans[i].v);
	}
	return 0;
}
