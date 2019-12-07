#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
const int N=310;
bool vis[150][N][N][8];
int mp[N][N];
int n,s[31];
struct state
{
	int x,y,dir,step;
	state(){}
	state(int _x,int _y,int _dir,int _step):
		x(_x),y(_y),dir(_dir),step(_step){}
};
int bfs()
{
	queue <state> q;
	q.push(state(151,151,1,1));
	while(!q.empty())
	{
		state u=q.front();q.pop();
		mp[u.x][u.y]=1;
		int nowstep=u.step;
		if(nowstep==s[n])continue;
		int nowdir=u.dir;
		if(vis[nowstep-1][u.x][u.y][nowdir-1])continue;
		vis[nowstep-1][u.x][u.y][nowdir-1]=1;
		bool End=false;
		for(int i=1;i<=n;++i)
		{
			if(nowstep==s[i])
			{
				End=true;
				switch(nowdir)
				{
				case 1:
					{
						q.push(state(u.x-1,u.y+1,8,nowstep+1));
						q.push(state(u.x+1,u.y+1,2,nowstep+1));
						break;
					}
				case 2:
					{
						q.push(state(u.x,u.y+1,1,nowstep+1));
						q.push(state(u.x+1,u.y,3,nowstep+1));
						break;
					}
				case 3:
					{
						q.push(state(u.x+1,u.y-1,4,nowstep+1));
						q.push(state(u.x+1,u.y+1,2,nowstep+1));
						break;
					}
				case 4:
					{
						q.push(state(u.x+1,u.y,3,nowstep+1));
						q.push(state(u.x,u.y-1,5,nowstep+1));
						break;
					}
				case 5:
					{
						q.push(state(u.x-1,u.y-1,6,nowstep+1));
						q.push(state(u.x+1,u.y-1,4,nowstep+1));
						break;
					}
				case 6:
					{
						q.push(state(u.x-1,u.y,7,nowstep+1));
						q.push(state(u.x,u.y-1,5,nowstep+1));
						break;
					}
				case 7:
					{
						q.push(state(u.x-1,u.y-1,6,nowstep+1));
						q.push(state(u.x-1,u.y+1,8,nowstep+1));
						break;
					}
				case 8:
					{
						q.push(state(u.x-1,u.y,7,nowstep+1));
						q.push(state(u.x,u.y+1,1,nowstep+1));
						break;
					}
				}
			}
		}
		if(End)continue;
		switch(nowdir)
		{
		case 1:
			{
				q.push(state(u.x,u.y+1,1,nowstep+1));
				break;
			}
		case 2:
			{
				q.push(state(u.x+1,u.y+1,2,nowstep+1));
				break;
			}
		case 3:
			{
				q.push(state(u.x+1,u.y,3,nowstep+1));
				break;
			}
		case 4:
			{
				q.push(state(u.x+1,u.y-1,4,nowstep+1));
				break;
			}
		case 5:
			{
				q.push(state(u.x,u.y-1,5,nowstep+1));
				break;
			}
		case 6:
			{
				q.push(state(u.x-1,u.y-1,6,nowstep+1));
				break;
			}
		case 7:
			{
				q.push(state(u.x-1,u.y,7,nowstep+1));
				break;
			}
		case 8:
			{
				q.push(state(u.x-1,u.y+1,8,nowstep+1));
				break;
			}
		}
	}
	int ret=0;
	for(int i=0;i<=309;++i)
		for(int j=0;j<=309;++j)
			ret+=mp[i][j];
	return ret;
}

int main()
{
	scanf("%d",&n);int t;
	for(int i=1;i<=n;++i)
		scanf("%d",&t),s[i]=s[i-1]+t;
	int ans=bfs();
	printf("%d\n",ans);
	return 0;
}