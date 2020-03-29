#include <bits/stdc++.h>
#define MAXN 200005
#define MAXM 1000005
using namespace std;

int n,x,cnt;
char s[15];
string str;
vector <int> a,g[MAXN];
map <string,int> mp;
map <vector<int>,int> mp2;

namespace Dinic
{
	struct link
	{
		int to, flow, nxt;
	};

	link e[MAXM << 1];
	int head[MAXN], cnt = 1;
	int dpt[MAXN];
	int S, T, ans;
	queue <int> q;

	inline void add(int u, int v, int f) //add edge u->v
	{
		e[++cnt] = (link)
		{
			v, f, head[u]
		};
		head[u] = cnt;
		e[++cnt] = (link)
		{
			u, 0, head[v]
		};
		head[v] = cnt;
	}

	inline bool BFS()
	{
		memset(dpt, -1, sizeof dpt);
		dpt[S] = 1;
		q.push(S);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; ~i; i = e[i].nxt)
				if (e[i].flow && !~dpt[e[i].to])
				{
					dpt[e[i].to] = dpt[x] + 1;
					q.push(e[i].to);
				}
		}
		return dpt[T] != -1;
	}

	inline int Dinic(int x, int flow)
	{
		int left = flow;
		if (x == T) return flow;
		for (int i = head[x]; ~i && left; i = e[i].nxt)
			if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
			{
				int t = Dinic(e[i].to, min(left, e[i].flow));
				e[i].flow -= t;
				e[i ^ 1].flow += t;
				left -= t;
			}
		if (left) dpt[x] = -1;
		return flow - left;
	}

	inline int goDinic()
	{
		while (BFS()) ans += Dinic(S, ~(1 << 31));
		return ans;
	}

	inline void makeGraph(int n)
	{
		S=0;T=n<<1|1;
		memset(head,-1,sizeof head);
		for (int i=1;i<=n;i++)
		{
			add(S,i,1);add(i+n,T,1);
			for (auto v:g[i]) add(i,v+n,1);
		}
		return ;
	}
}

vector <int> now;
int cnt2;

inline int f(int p)
{
	now.clear();
	for (int i=0;i<x;i++) if (p&(1<<i)) now.push_back(a[i]);
	if (!mp2.count(now)) mp2.insert({now,++cnt2});
	return mp2[now];
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);a.clear();
		for (int j=1;j<=x;j++)
		{
			scanf("%s",s);str="";
			for (int k=0,l=strlen(s);k<l;k++) str+=s[k];
			if (!mp.count(str)) mp.insert({str,++cnt});
			a.push_back(mp[str]);
		}
		sort(a.begin(),a.end());
		for (int j=(1<<x)-1;j;j--)
		{
			int id=f(j);
			for (int k=0;k<x;k++)
				if (j&(1<<k))
					g[id].push_back(f((1<<k)^j));
		}
	}
	Dinic::makeGraph(cnt2);
	printf("%d\n",cnt2-Dinic::goDinic());
	return 0;
}