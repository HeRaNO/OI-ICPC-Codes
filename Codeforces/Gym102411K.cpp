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
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,m;
char s[1005][1005];

bool ok(int i,int j)
{
	return s[i][j]=='.'||s[i][j]=='A';
}

int x=0,y=0;
int l[1005][1005],r[1005][1005],u[1005][1005];

int calc(int i,int j)
{
	return (r[i][j]-l[i][j]+1)*u[i][j];
}

int AX,AY;

bool check(int i,int j)
{
	return l[i][j]<=AY&&r[i][j]>=AY&&i>=AX&&i-u[i][j]+1<=AX;
}

bool vis[MAXN];
vector<pii> v;

char bio(char c)
{
	if(c>='A'&&c<='Z')return c-'A'+'a';
	return c;
}

void chock(int p,int l,int r,char ch)
{
	if(p>x)return;
	if(p<x-u[x][y]+1)return;
	for(int i=l;i<=r;i++){if(s[p][i]!='.')return;}
	for(int i=l;i<=r;i++)s[p][i]=ch;
	chock(p+1,l,r,ch);
	chock(p-1,l,r,ch);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='A')AX=i,AY=j;
			if(s[i][j]>'A'&&s[i][j]<='Z')v.pb({i,j});
			l[i][j]=r[i][j]=j,u[i][j]=1;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		if(ok(i,j)&&ok(i,j-1))l[i][j]=l[i][j-1];
		for(int j=m;j;j--)
		if(ok(i,j)&&ok(i,j+1))r[i][j]=r[i][j+1];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i>1&&ok(i,j)&&ok(i-1,j))
			{
				l[i][j]=max(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
				u[i][j]=u[i-1][j]+1;
			}
			if(check(i,j)&&calc(i,j)>calc(x,y))x=i,y=j;
		}
	for(int i=x-u[x][y]+1;i<=x;i++)
		for(int j=l[x][y];j<=r[x][y];j++)
			if(s[i][j]=='.')s[i][j]='a';
	for(int i=x-u[x][y]+1;i<=x;i++)vis[i]=1;
	queue<int> q;
	for(auto i:v)
	{
		int l=i.se,r=i.se;
		if(i.fi>x||i.fi<x-u[x][y]+1)continue;
		for(int j=i.se-1;j;j--)
		{
			if(s[i.fi][j]!='.')break;
			s[i.fi][j]=s[i.fi][i.se]-'A'+'a';
			l=j;
		}
		for(int j=i.se+1;j<=m;j++)
		{
			if(s[i.fi][j]!='.')break;
			s[i.fi][j]=s[i.fi][i.se]-'A'+'a';
			r=j;
		}
		chock(i.fi-1,l,r,s[i.fi][i.se]-'A'+'a');
		chock(i.fi+1,l,r,s[i.fi][i.se]-'A'+'a');
	}
	for(auto i:v)
	{
		if(i.fi<=x&&i.fi>=x-u[x][y]+1)continue;
		for(int j=i.se-1;j;j--)
		{
			if(s[i.fi][j]!='.')break;
			s[i.fi][j]=s[i.fi][i.se]-'A'+'a';
		}
		for(int j=i.se+1;j<=m;j++)
		{
			if(s[i.fi][j]!='.')break;
			s[i.fi][j]=s[i.fi][i.se]-'A'+'a';
		}
		if(i.fi>1&&!vis[i.fi-1])q.push(i.fi-1);
		if(i.fi<n&&!vis[i.fi+1])q.push(i.fi+1);
	}
	while(!q.empty())
	{
		int i=q.front();q.pop();
		if(vis[i])continue;
		for(int j=1;j<=m;j++)
		{
			if(s[i-1][j]!='.'&&i>1&&s[i][j]=='.')s[i][j]=bio(s[i-1][j]);
			else if(s[i+1][j]!='.'&&i<n&&s[i][j]=='.')s[i][j]=bio(s[i+1][j]);
		}
		vis[i]=1;
		if(i>1&&!vis[i-1])q.push(i-1);
		if(i<n&&!vis[i+1])q.push(i+1);
	}
	for(int i=1;i<=n;i++)printf("%s\n",s[i]+1);
	return 0;
}
