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
typedef pair<db,ll> pii;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,m,h;
char s[105][105],t[105][105];
struct Node
{
	int x,y,z;
	bool operator < (const Node &rhs)const
	{
		return x^rhs.x?x<rhs.x:y^rhs.y?y<rhs.y:z<rhs.z;
	}
};

vector<Node> ans;

void getmax()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		if(s[i][j]-'0')
		{
			for(int k=0;k<h;k++)if(t[i][k]-'0')ans.pb({i,j,k});
		}
	printf("%d\n",SZ(ans));
	sort(ALL(ans));
	for(auto j:ans)printf("%d %d %d\n",j.x,j.y,j.z);
}

void getmin()
{
	ans.clear();
	for(int i=0;i<n;i++)
	{
		int fj=m,fk=h;
		for(int j=m-1,k=h-1;j>-1&&k>-1;j--,k--)
		{
			while(j>-1&&s[i][j]=='0')j--;
			while(k>-1&&t[i][k]=='0')k--;
			if(j>-1&&k>-1)
			{
				fj=j;
				fk=k;
				ans.pb({i,j,k});
			}
		}
		for(int j=fj-1;j>-1;j--)
		{
			if(s[i][j]=='1')
			{
				for(int k=0;k<h;k++)if(t[i][k]=='1')
				{
					ans.pb({i,j,k});
					break;
				}
			}
		}
		for(int k=fk-1;k>-1;k--)
		{
			if(t[i][k]=='1')
				for(int j=0;j<m;j++)
				if(s[i][j]=='1')
				{
					ans.pb({i,j,k});
					break;
				}
		}
	}
	sort(ALL(ans));
	printf("%d\n",SZ(ans));
	for(auto j:ans)printf("%d %d %d\n",j.x,j.y,j.z);
}

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++)scanf("%s",t[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<h;j++)
		{
			if(t[i][j]-'0')
			{
				bool f=1;
				for(int k=0;k<m;k++)if(s[i][k]-'0')f=0;
				if(f)return puts("-1"),0;
			}
		}
		for(int j=0;j<m;j++)
		{
			if(s[i][j]-'0')
			{
				bool f=1;
				for(int k=0;k<h;k++)if(t[i][k]-'0')f=0;
				if(f)return puts("-1"),0;
			}
		}
	}
	getmax();
	getmin();
	return 0;
}