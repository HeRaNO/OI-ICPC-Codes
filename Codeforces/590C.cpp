#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair((a),(b))
typedef pair<int,int> pii;
#define ll long long
const int INF=99999999;
int n,m;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=1050;
pii st[5];
char s[N][N];
int v[4][N][N];
bool vis[N][N];
inline bool iscountry(char c)
{
	return c>='1'&&c<='3';
}
void bfs(int id)
{
	deque <pii> q;
	q.push_back(st[id]);
	v[id][st[id].first][st[id].second]=1;
	while(!q.empty())
	{
		pii u=q.front();q.pop_front();
		for(int k=0;k<4;++k)
		{
			int ux=u.first;
			int uy=u.second;
			int nx=ux+dx[k];
			int ny=uy+dy[k];
			if(s[nx][ny]=='#'||nx<1||nx>n||ny<1||ny>m)continue;
			if(!v[id][nx][ny])
			{
				if(iscountry(s[nx][ny]))
					v[id][nx][ny]=v[id][ux][uy],q.push_front({nx,ny});
				else
					v[id][nx][ny]=v[id][ux][uy]+1,q.push_back({nx,ny});
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='1')st[1]=mp(i,j);
			if(s[i][j]=='2')st[2]=mp(i,j);
			if(s[i][j]=='3')st[3]=mp(i,j);
		}
	for(int i=1;i<=3;++i)bfs(i);
	int ans=INF;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int now=0;
			if(s[i][j]=='#')continue;
			if(!v[1][i][j])continue;
			if(!v[2][i][j])continue;
			if(!v[3][i][j])continue;
			for(int id=1;id<=3;++id)
				now+=v[id][i][j];
			if(!iscountry(s[i][j]))now-=2;
			ans=min(ans,now-3);
		}
	if(ans==INF)printf("-1");
	else printf("%d\n",ans);
	return 0;
}