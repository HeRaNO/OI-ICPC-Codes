#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const db Pi=acos(-1);

struct Node
{
	db t,s,a,k;
	bool operator < (const Node &rhs)const
	{
		return a<rhs.a;
	}
}e[MAXN];
vector<Node>v;

db dist (db a,db b)
{
	return min(fabs(a-b),2*Pi-fabs(a-b));
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&e[i].t,&e[i].s,&e[i].a);
		e[i].k=e[i].s*(-2);
		v.pb(e[i]);
		if(e[i].t-e[i].s*Pi>0)
		{
			db tmp=e[i].a+Pi;
			if(tmp>=Pi*2)tmp-=Pi*2;
			Node t=e[i];t.k=-e[i].k;t.a=tmp;
			v.pb(t);
		}
		else
		{
			db tmp=e[i].a+e[i].t/e[i].s;
			if(tmp>=Pi*2)tmp-=Pi*2;
			Node t=e[i];t.k=e[i].s;t.a=tmp;
			v.pb(t);
			tmp=e[i].a-e[i].t/e[i].s;
			if(tmp<0)tmp+=Pi*2;
			t=e[i];t.k=e[i].s;t.a=tmp;
			v.pb(t);
		}
	}
	sort(ALL(v));
	db ans=0,res=0,k=0;
	for(int i=1;i<=n;i++)
	{
		res+=max(0.0,e[i].t-e[i].s*dist(e[i].a,v[0].a));
		db tmp=(e[i].a-v[0].a);
		if(e[i].t/e[i].s<Pi)
		{
			db l=e[i].a-e[i].t/e[i].s,r=e[i].a+e[i].t/e[i].s;
			if(l<0)l+=2*Pi;if(r>=2*Pi)r-=2*Pi;
			if(l<r)
			{
				if(v[0].a>=l&&v[0].a<e[i].a)k+=e[i].s;
				else if(v[0].a>=e[i].a&&v[0].a<r)k-=e[i].s;
			}
			else if(e[i].a<l)
			{
				if(v[0].a>=l||v[0].a<e[i].a)k+=e[i].s;
				else if(v[0].a<r)k-=e[i].s;
			}
			else
			{
				if(v[0].a>=l&&v[0].a<e[i].a)k+=e[i].s;
				else if(v[0].a>=e[i].a||v[0].a<r)k-=e[i].s;
			}
		}
		else if(tmp>Pi||tmp==0)k-=e[i].s;
		else k+=e[i].s;
	}
	ans=res;
	for(int i=1;i<SZ(v);i++)
	{
		res+=k*(v[i].a-v[i-1].a);
		ans=max(ans,res);
		k+=v[i].k;
	}
	printf("%.12lf",ans);
	return 0;
}
