#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int MAXN=1e7+10,MAXM=4e7+10;
const int INF=~(1<<31),MOD=1e9+7;
const ll llINF=((1ll<<61));

vector <pii> v[MAXN];
int n,m;
int dex[]={1,1,-1,-1},dey[]={1,-1,1,-1};
int mp[MAXM];

int calc(int i,int j)
{
	if(i>6000||i<1||j<1||j>6000)return 0;
	return (i-1)*6000+j;
}

void init()
{
	for(int i=0;i<=6000;i++)
		for(int j=0;j<=6000;j++)
		{
			if(i*i+j*j<=1e7)
				v[i*i+j*j].push_back({i,j});
			else break;
		}
}

int a[20000],cnt;

void add(int w,int z,int x,int y)
{
	for(int i=0;i<v[w].size();i++)
	{
		int dx=v[w][i].first,dy=v[w][i].second;
		cnt=0;
		for(int j=0;j<4;j++)
		{
			int tag=calc(x+dx*dex[j],y+dy*dey[j]);
			if(!tag)continue;
			a[++cnt]=tag;
		}
		sort(a+1,a+cnt+1);
		for(int j=1;j<=cnt;j++)
			if(a[j]!=a[j-1])
			if(mp[a[j]])mp[a[j]]+=z;
	}
}
ll lastans;
void solve(int w,int x,int y)
{
	for(int i=0;i<v[w].size();i++)
	{
		int dx=v[w][i].first,dy=v[w][i].second;
		cnt=0;
		for(int j=0;j<4;j++)
		{
			int tag=calc(x+dx*dex[j],y+dy*dey[j]);
			if(!tag)continue;
			a[++cnt]=tag;
		}
		sort(a+1,a+cnt+1);
		for(int j=1;j<=cnt;j++)
			if(a[j]!=a[j-1])
			lastans+=mp[a[j]];
	}
}

vector<int> tbc;

int main()
{
	init();
	int t;
	scanf("%d",&t);
	for(int kase=1;kase<=t;kase++)
	{
		scanf("%d%d",&n,&m);
		tbc.resize(0);
		for(int i=1;i<=n;i++)
		{
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			mp[calc(x,y)]=w;
			tbc.push_back(calc(x,y));
		}
		printf("Case #%d:\n",kase);
		lastans=0;
		for(int i=1;i<=m;i++)
		{
			int op,x,y,w,z;
			scanf("%d%d%d",&op,&x,&y);
			x=(lastans+x)%6000+1;
			y=(lastans+y)%6000+1;
			if(op==1)
			{
				scanf("%d",&w);
				mp[calc(x,y)]=w;
				tbc.push_back(calc(x,y));
			}
			if(op==2)
			{
				mp[calc(x,y)]=0;
			}
			if(op==3)
			{
				scanf("%d%d",&w,&z);
				add(w,z,x,y);
			}
			if(op==4)
			{
				scanf("%d",&w);
				lastans=0;
				solve(w,x,y);
				printf("%lld\n",lastans);
			}
		}
		for(int i=0;i<tbc.size();i++)
			mp[tbc[i]]=0;
	}
	return 0;
}