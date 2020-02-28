#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e6+10,MAXM=2e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

int n;
vector<int> v[2];
int dp[7005][2];
int cnt[7005][2];

queue<pii> q;

void winwin()
{
	for(int o=0;o<=1;o++)
	{
		for(auto j:v[o])
		{
			dp[n-j][o]=1-o*2;
			q.push({n-j,o});
		}
	}
	while(!q.empty())
	{
		int x,y;
		tie(x,y)=q.front();q.pop();
		if(!x)continue;
		//cout<<x<<" "<<y<<" "<<dp[x][y]<<" "<<cnt[x][y]<<endl;
		if(dp[x][y]!=1-y*2)
		{
			for(auto j:v[y^1])
			{
				if(!dp[(x-j+n)%n][y^1])
				{
					dp[(x-j+n)%n][y^1]=dp[x][y];
					q.push({(x-j+n)%n,y^1});
				}
			}
		}
		else if(dp[x][y]!=-1+y*2)
		{
			for(auto j:v[y^1])
			{
				if(!dp[(x-j+n)%n][y^1])
				{
					cnt[(x-j+n)%n][y^1]++;
					if(cnt[(x-j+n)%n][y^1]==SZ(v[y^1]))
					{
						q.push({(x-j+n)%n,y^1});
						dp[(x-j+n)%n][y^1]=dp[x][y];
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	int k1,k2;
	scanf("%d",&k1);
	while(k1--)
	{
		int p;scanf("%d",&p);
		v[0].push_back(p);
	}
	scanf("%d",&k2);
	while(k2--)
	{
		int p;scanf("%d",&p);
		v[1].push_back(p);
	}
	sort(ALL(v[0]));
	sort(ALL(v[1]));
	winwin();
	for(int o=0;o<=1;o++,puts(""))
	for(int i=1;i<n;i++)
	{
		if(dp[i][o]==1-o*2)printf("Win ");
		else if(dp[i][o]==0)printf("Loop ");
		else printf("Lose ");
	}
	return 0;
}
