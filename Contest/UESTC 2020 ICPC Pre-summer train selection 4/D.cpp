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
const int MAXN=2e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const db Pi=acos(-1);

const int M=1e5+7;

long long s[MAXN][2];
int n,m,l,r,v,ans;
char o[3];

struct Matrix
{
	int m[7][7],n;
	Matrix(){
		for (int i=0;i<7;i++)
			for (int j=0;j<7;j++)
				m[i][j]=(i==j);
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;res.n=n;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				res.m[i][j]=0;
				for (int k=0;k<n;k++)
					(res.m[i][j]+=1LL*m[i][k]*a.m[k][j]%M)%=M;
			}
		return res;
	}
};

inline void inc(int p,int l,int r,int v)
{
	l=max(l,0);r=max(r,-1);
	s[l][p]+=v;s[r+1][p]-=v;
	return ;
}

inline int make(int n,long long p)
{
	if (!n) return 0;
	if (n==1) return 1;
	if (p<=n) return 1;p-=n;
	Matrix r,b;r.n=b.n=n;memset(b.m,0,sizeof b.m);
	for (int i=0;i<n;i++) b.m[0][i]=1;
	for (int i=0;i<n-1;i++) b.m[i+1][i]=1;
	for (;p;p>>=1,b=b*b) if (p&1) r=r*b;
	int ans=0;
	for (int i=0;i<n;i++) (ans+=r.m[0][i])%=M;
	return ans;
}

int main()
{
    //freopen("06.in","r",stdin);
    //freopen("06.out","w",stdout);
	scanf("%d %d",&n,&m);inc(0,0,n-1,1);inc(1,0,n-1,1);
	for (int i=1;i<=m;i++)
	{
		scanf("%s %d %d %d",o,&l,&r,&v);--l;--r;
		if (l<=r) inc(o[0]-'a',l,r,v);
		else
		{
			inc(o[0]-'a',l,n-1,v);
			inc(o[0]-'a',0,r,v);
		}
	}
	for(int i=1;i<n;i++)
		s[i][0]+=s[i-1][0],s[i][1]+=s[i-1][1];
	for (int i=0;i<n;i++) ans+=make(s[i][1]%7,s[i][0]);
	printf("%d\n",ans);
	return 0;
}