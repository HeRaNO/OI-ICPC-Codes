#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 250010

using namespace std;

int Head[M], Next[M], Go[M], Pre[1010], Nxt[1010], F[1010], S[1010], Q[1010], Vis[1010], *Top = Q, Cnt = 0, Tim = 0, n, m, x, y;

inline void addedge(int x, int y)
{
	Go[++Cnt] = y;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
	Go[++Cnt] = x;
	Next[Cnt] = Head[y];
	Head[y] = Cnt;
}

int find(int x)
{
	return x == F[x] ? x : F[x] = find(F[x]);
}

int lca(int x, int y)
{
	for(Tim++, x = find(x), y = find(y); ; x ^= y ^= x ^= y)
		if(x)
		{
			if(Vis[x] == Tim) return x;
			Vis[x] = Tim;
			x = find(Pre[Nxt[x]]);
		}
}

void blossom(int x, int y, int l)
{
	while(find(x) != l)
	{
		Pre[x] = y, y = Nxt[x];
		S[*Top = y] = 0, *Top++;
		if(F[x] == x) F[x] = l;
		if(F[y] == y) F[y] = l;
		x = Pre[y];
	}
	return ;
}

int Match(int x,int n)
{
	for(int i = 1; i <= n; i++) F[i] = i;
	memset(S, -1, sizeof S);
	S[*(Top = Q) = x] = 0, Top++;
	for(int *i = Q; i != Top; *i++)
		for(int T = Head[*i]; T; T = Next[T])
		{
			int g = Go[T];
			if(S[g] == -1)
			{
				Pre[g] = *i, S[g] = 1;
				if(!Nxt[g])
				{
					for(int u = g, v = *i, lst; v; u = lst, v = Pre[u])
						lst = Nxt[v], Nxt[v] = u, Nxt[u] = v;
					return 1;
				}
				S[*Top = Nxt[g]] = 0, Top++;
			}
			else if(!S[g] && find(g) != find(*i))
			{
				int l = lca(g, *i);
				blossom(g, *i, l);
				blossom(*i, g, l);
			}
		}
	return 0;
}

int d[1000],idx[1000][2];

inline void Solve()
{
	int s=0;Cnt=Tim=0;
	memset(Nxt,0,sizeof Nxt);memset(Head,0,sizeof Head);
	memset(Pre,0,sizeof Pre);
	memset(Q,0,sizeof Q);memset(Vis,0,sizeof Vis);
	memset(idx,0,sizeof idx);
	Top=Q;int cnt=0,p=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);s+=d[i];
		idx[i][0]=++cnt;
		if(d[i]==2)idx[i][1]=++cnt;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(d[u]>d[v])swap(u,v);
		if(d[u]==2&&d[v]==2)
		{
			cnt+=2;
			addedge(idx[u][0],cnt-1);
			addedge(idx[u][1],cnt-1);
			addedge(idx[v][0],cnt);
			addedge(idx[v][1],cnt);
			addedge(cnt-1,cnt);
			p++;
		}
		else
		{
			addedge(idx[u][0],idx[v][0]);
			if(d[v]==2)addedge(idx[u][0],idx[v][1]);
		}
	}
	if (s&1) return puts("No"),void();
	int ans=0;
	for(int i=cnt;i;i--) if (!Nxt[i]) ans+=Match(i,cnt);
	//printf("%d %d %d\n",ans,p,s);
	if (ans==s/2+p) puts("Yes");
	else puts("No");
	return ;
}

int main()
{
	int T;
	while (scanf("%d %d",&n,&m)==2) Solve();
	return 0;
}