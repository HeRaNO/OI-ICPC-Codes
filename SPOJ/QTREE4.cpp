#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct link{int to,val,nxt;};

struct DelHeap
{
	priority_queue <int> a,b;
	void upd()
	{
		while (!b.empty()&&a.top()==b.top())
			a.pop(),b.pop();
		return ;
	}
	void push(int x){a.push(x);return ;}
	void del(int x){b.push(x);return ;}
	void pop(){upd();a.pop();return ;}
	int top(){upd();return a.top();}
	int sectop(){int t=top();pop();int r=top();push(t);return r;}
	int size(){return a.size()-b.size();}
	bool empty(){return a.size()==b.size();}
};

link e[MAXN<<1];
int head[MAXN],cnt,wcnt;
int n,u,v,w,T,R,SIZE,G,o,x,lg[MAXN<<1],pt[MAXN],euler[MAXN<<1];
int siz[MAXN],mx[MAXN],f[MAXN],dis[MAXN],dep[MAXN<<1],fa[18][MAXN<<1];
bool vis[MAXN],c[MAXN];
DelHeap ans,a[MAXN],all[MAXN];

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int f,int deep,int v)
{
	pt[x]=++R;euler[R]=x;dep[R]=deep;dis[x]=v;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			dfs(e[i].to,x,deep+1,e[i].val+v);
			euler[++R]=x;dep[R]=deep;
		}
	return ;
}

inline void RMQLCA()
{
	for (int i=1;i<=R;i++) fa[0][i]=i;
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
		{
			int a=fa[j-1][i],b=fa[j-1][i+(1<<(j-1))];
			fa[j][i]=dep[a]<=dep[b]?a:b;
		}
	return ;
}

inline int getLCA(int x,int y)
{
	x=pt[x];y=pt[y];
	if (x>y) swap(x,y);
	int t=lg[y-x+1];int a=fa[t][x],b=fa[t][y-(1<<t)+1];
	return dep[a]<=dep[b]?euler[a]:euler[b];
}

inline int getdis(int x,int y)
{
	return dis[x]+dis[y]-2*dis[getLCA(x,y)];
}

inline void DFS_size_and_G(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	for(int i=head[x];~i;i=e[i].nxt)
		if(e[i].to!=fa&&!vis[e[i].to])
		{
			DFS_size_and_G(e[i].to,x);
			siz[x]+=siz[e[i].to];
			mx[x]=max(mx[x],siz[e[i].to]);
		}
	mx[x]=max(mx[x],SIZE-siz[x]);
	if (mx[x]<mx[G]) G=x;
	return ;
}

inline void downdate(int x)
{
	if (all[x].size()>1) ans.del(all[x].top()+all[x].sectop());
	return ;
}

inline void update(int x)
{
	if (all[x].size()>1) ans.push(all[x].top()+all[x].sectop());
	return ;
}

void Calc(int x,int fa,int v)
{
	a[G].push(v);
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to]&&e[i].to!=fa)
			Calc(e[i].to,x,e[i].val+v);
	return ;
}

inline void TreeDC(int x)
{
	vis[x]=true;
	for(int i=head[x];~i;i=e[i].nxt)
		if(!vis[e[i].to])
		{
			mx[0]=SIZE=siz[e[i].to];G=0;
			DFS_size_and_G(e[i].to,x);f[G]=x;
			Calc(e[i].to,x,e[i].val);all[x].push(a[G].top());
			TreeDC(G);
		}
	all[x].push(0);update(x);
	vis[x]=false;
	return ;
}

inline void modify(int x)
{
	c[x]=!c[x];c[x]?--wcnt:++wcnt;
	downdate(x);c[x]?all[x].del(0):all[x].push(0);update(x);
	for (int i=x;f[i];i=f[i])
	{
		downdate(f[i]);int d=getdis(x,f[i]);
		if (!a[i].empty()) all[f[i]].del(a[i].top());
		c[x]?a[i].del(d):a[i].push(d);
		if (!a[i].empty()) all[f[i]].push(a[i].top());
		update(f[i]);
	}
	return ;
}

inline void query()
{
	if (!wcnt) puts("They have disappeared.");
	else if (wcnt==1) puts("0");
	else printf("%d\n",max(ans.top(),0));
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9')
	{
		if (ch=='A') {x=0;return ;}
		if (ch=='C') {x=1;return ;}
		if (ch=='-') f=true;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(n);wcnt=n;
	for (int i=1;i<n;i++){read(u);read(v);read(w);add(u,v,w);}
	dfs(1,-1,0,0);RMQLCA();
	SIZE=mx[0]=n;DFS_size_and_G(1,-1);TreeDC(G);
	read(T);
	while (T--)
	{
		read(o);
		if (!o) query();
		else read(x),modify(x);
	}
	return 0;
}