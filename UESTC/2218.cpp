#include <bits/stdc++.h>
#define MAXN 500010
#define MAXM 600010
using namespace std;

struct node
{
	long long d;int u;
	bool operator < (const node &a)const{
		return d>a.d;
	}
};

struct link
{
	int to,val,nxt;
};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,m,T,u,v,c,dis[MAXN];
bool vis[MAXN];
priority_queue <node> q;
map <pair<int,int>,int> mp;

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline int Dijkstra()
{
	memset(dis,0x7f,sizeof dis);q.push((node){0,1});dis[1]=0;
	while (!q.empty())
	{
		node x=q.top();q.pop();
		if (vis[x.u]) continue;vis[x.u]=true;
		for (int i=head[x.u];~i;i=e[i].nxt)
			if (dis[e[i].to]>dis[x.u]+e[i].val)
			{
				dis[e[i].to]=dis[x.u]+e[i].val;
				q.push((node){dis[e[i].to],e[i].to});
			}
	}
	return dis[n]==0x7f7f7f7f?-1:dis[n]>>1;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(n);read(m);T=n;
	for (int i=1;i<=m;i++)
	{
		read(u);read(v);read(c);
		if (!mp.count(make_pair(v,c)))
		{
			mp.insert(make_pair(make_pair(v,c),++T));
			add(v,mp[make_pair(v,c)],1);
		}
		if (!mp.count(make_pair(u,c)))
		{
			mp.insert(make_pair(make_pair(u,c),++T));
			add(u,mp[make_pair(u,c)],1);
		}
		add(mp[make_pair(v,c)],mp[make_pair(u,c)],0);
	}
	printf("%d\n",Dijkstra());
	return 0;
}
