#include <bits/stdc++.h>
#define MAXM 11000000
#define MAXN 1000010
using namespace std;

struct link
{
	int to,val,nxt;
};

link e[MAXM];
int head[MAXN],cnt;
int dis[MAXN];
bool vis[MAXN];
set <pair<int,int> > s;
queue <int> q;

void addEdge(int u,int v,int w)
{
	if (u==v) return ;
	if (s.count(make_pair(u,v))) return ;
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	return ;
}

void buildGraph(int N, int Seed) {
    int nextRand = Seed;
    for (int x = 1; x <= N; x++) {
        int w = x % 10 + 1;
        int d = 10 - w;
        for (int i = 1; i <= d; i++) {
            addEdge(x, nextRand % N + 1, w);
            nextRand = nextRand * 233 % N;
        }
        addEdge(x, x % N + 1, w);
    }
}

inline int SPFA(int T)
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, false, sizeof vis);
	dis[1] = 0;
	vis[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return dis[T];
}

int main()
{
	int n,seed,T;
	scanf("%d",&T);
	while (T--)
	{
		memset(head,-1,sizeof head);s.clear();cnt=0;
		scanf("%d %d",&n,&seed);
		buildGraph(n,seed);
		printf("%d\n",SPFA(n));
	}
	return 0;
}