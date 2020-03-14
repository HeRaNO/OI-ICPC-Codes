#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int Lim=(1<<19);

struct Matrix
{
	ll a[5][5];
	Matrix operator * (const Matrix &rhs)const
	{
		Matrix res;
		memset(res.a,0,sizeof(res.a));
			for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				for(int k=0;k<5;k++)
				(res.a[i][j]+=a[i][k]*rhs.a[k][j])%=MOD;
		return res;
	}
};
Matrix ksm(Matrix base,int v)
{
	Matrix res;
	memset(res.a,0,sizeof(res.a));
	res.a[0][1]=res.a[0][3]=res.a[0][4]=1;
	res.a[0][0]=3;
	// follows with your own Matrix
	while(v)
	{
		if(v&1)(res=res*base);
		base=base*base;
		v>>=1;
	}
	return res;
}

ll qksm(ll x,ll v)
{
	ll ans=1;
	while(v)
	{
		if(v&1)(ans*=x)%=MOD;
		(x*=x)%=MOD;
		v>>=1;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	if(n==1)return puts("2"),0;
	if(n==2)return puts("24"),0;
	Matrix tmp;
	memset(tmp.a,0,sizeof(tmp.a));
	tmp.a[1][2]=tmp.a[0][1]=tmp.a[0][4]=tmp.a[4][4]=tmp.a[3][3]=1;
	tmp.a[0][0]=tmp.a[1][0]=tmp.a[3][0]=1;
	Matrix ans=ksm(tmp,n-3);
	ll ans1=ans.a[0][4];
	ll ans2=(ans.a[0][0]+ans.a[0][1]+1)%MOD;
	cout<<(ans1+ans2)%MOD*qksm(2,n+1)%MOD;
	return 0;
}
