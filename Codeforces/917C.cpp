#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e6+10,MAXM=1e4+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;
const ll llINF=~(1ll<<63);

int mp[305],cnt,c[20];

struct Matrix
{
	ll a[80][80];
	void init()
	{
		memset(a,0x3f,sizeof(a));
		for(int i=0;i<80;i++)a[i][i]=0;
	}
	Matrix operator * (const Matrix &b)const
	{
		Matrix res;
		memset(res.a,0x3f,sizeof(res.a));
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
			for(int k=1;k<=cnt;k++)
			res.a[i][j]=min(a[i][k]+b.a[k][j],res.a[i][j]);
		return res;
	}
};

Matrix ksm(Matrix x,ll v)
{
	Matrix res;
	res.init();
	while(v)
	{
		if(v&1)res=res*x;
		x=x*x;
		v>>=1;
	}
	return res;
}

int main()
{
	int x,k,n,q;
	scanf("%d%d%d%d",&x,&k,&n,&q);
	for(int i=1;i<=k;i++)scanf("%d",&c[i]);
	for(int i=0;i<(1<<k);i++)
	{
		if(x==__builtin_popcount(i))
			mp[i]=++cnt;
	}
	Matrix ans,base;
	memset(base.a,0x3f,sizeof(base.a));
	ans.init();
	for(int i=0;i<(1<<k);i++)
	{
		if(!mp[i])continue;
		if(i&1)
		{
			for(int j=1;j<=k;j++)
			{
				if((1<<j)&i)continue;
				base.a[mp[i]][mp[((1<<j)|i)>>1]]=c[j];
			}
		}
		else
		{
			base.a[mp[i]][mp[i>>1]]=0;
		}
	}
	vector<pii> v;
	for(int i=1;i<=q;i++)
	{
		int u,p;
		scanf("%d%d",&u,&p);
		v.push_back({u,p});
	}
	sort(v.begin(),v.end());
	ll tmp=0,lst=1;
	for(auto j:v)
	{
		int f=j.first,s=j.second;
		if(f>n-x)
		{
			tmp+=s;
			continue;
		}
		ans=ans*ksm(base,f-lst);
		lst=f;
		for(int j=1;j<(1<<k);j+=2)
		{
			if(mp[j])
			{
				for(int i=1;i<=cnt;i++)
					ans.a[i][mp[j]]+=s;
			}
		}
	}
	ans=ans*ksm(base,n-x+1-lst);
	cout<<ans.a[1][1]+tmp;
	return 0;
}