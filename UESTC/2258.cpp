#include <bits/stdc++.h>
#define MAXN 35
#define maxn 3605
#define MAXM 4505
using namespace std;

const int d[4][2]={
	{1,0},{-1,0},
	{0,1},{0,-1}
};

struct link{int to,val,nxt;};

struct node
{
	int d,u;
	bool operator < (const node &a)const{
		return d>a.d;
	}
};

link e[MAXM];
int head[maxn],cnt;
int n,m,T,a[MAXN][MAXN],ex,ey,sx,sy,tx,ty;
int dis[maxn],ds[MAXN][MAXN];
bool vis[maxn];
queue <pair<int,int> > q;
priority_queue <node> Q;

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
}

inline int ID(int x,int y){return (x-1)*m+y;}
inline int getpt(int ps,int i){return ((ps-1)<<2)+i+1;}

inline void BFS(int stx,int sty,int edx,int edy,int p)
{
	memset(ds,0,sizeof ds);
	q.push(make_pair(stx,sty));ds[stx][sty]=1;
	while (!q.empty())
	{
		pair<int,int> x=q.front();q.pop();
		int nx=x.first,ny=x.second,tx,ty;
		if (nx==edx&&ny==edy) continue;
		for (int i=0;i<4;i++)
		{
			tx=nx+d[i][0];ty=ny+d[i][1];
			if (!a[tx][ty]||ds[tx][ty]) continue;
			ds[tx][ty]=ds[nx][ny]+1;
			q.push(make_pair(tx,ty));
		}
	}
	if (!~p) return ;
	for (int i=0;i<4;i++)
	{
		int tx=edx+d[i][0],ty=edy+d[i][1];
		if (tx==stx&&ty==sty||!ds[tx][ty]) continue;
		add(getpt(ID(edx,edy),p),getpt(ID(edx,edy),i),ds[tx][ty]-1);
	}
	add(getpt(ID(edx,edy),p),getpt(ID(stx,sty),p^1),1);
	return ;
}

inline int Dijkstra(int stx,int sty,int edx,int edy)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	for (int i=0;i<4;i++)
		if (ds[stx+d[i][0]][sty+d[i][1]])
		{
			int pt=getpt(ID(stx,sty),i);
			dis[pt]=ds[stx+d[i][0]][sty+d[i][1]]-1;Q.push((node){dis[pt],pt});
		}
	while (!Q.empty())
	{
		node x=Q.top();Q.pop();
		if (vis[x.u]) continue;vis[x.u]=true;
		for (int i=head[x.u];~i;i=e[i].nxt)
			if (dis[e[i].to]>dis[x.u]+e[i].val)
			{
				dis[e[i].to]=dis[x.u]+e[i].val;
				Q.push((node){dis[e[i].to],e[i].to});
			}
	}
	int res=0x3f3f3f3f;
	for (int i=0;i<4;i++) res=min(res,dis[getpt(ID(edx,edy),i)]);
	return res==0x3f3f3f3f?-1:res;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(n);read(m);read(T);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			read(a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j])
			{
				for (int k=0;k<4;k++)
				{
					tx=i+d[k][0];ty=j+d[k][1];
					if (a[tx][ty]) BFS(tx,ty,i,j,k);
				}
			}
	while (T--)
	{
		read(ex);read(ey);read(sx);read(sy);read(tx);read(ty);
		if (sx==tx&&sy==ty) puts("0");
		else
		{
			BFS(ex,ey,sx,sy,-1);
			printf("%d\n",Dijkstra(sx,sy,tx,ty));
		}
	}
	return 0;
}
