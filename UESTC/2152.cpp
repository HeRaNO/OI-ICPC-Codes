#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,m,ans,a[MAXN],pre[MAXN],nxt[MAXN];
priority_queue<pair<int,int>, vector<pair<int,int> > > q;
bool vis[MAXN];

void del(int x)
{
	vis[x]=true;
	int p=pre[x],n=nxt[x];
	pre[x]=nxt[x]=-1;nxt[p]=n;pre[n]=p;
	return ;
}

inline void read(int &x)
{
	x=0;char ch;bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(m);
	if ((m<<1)>n) return puts("Error!"),0;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=2;i<=n;i++) pre[i]=i-1;pre[1]=n;
	for (int i=1;i<n;i++)  nxt[i]=i+1;nxt[n]=1;
	for (int i=1;i<=n;i++) q.push(make_pair(a[i],i));
	for (int i=1;i<=m;i++)
	{
		while (vis[q.top().second]) q.pop();
		int x=q.top().second;ans+=a[x];q.pop();
		a[x]=a[pre[x]]+a[nxt[x]]-a[x];
		del(pre[x]);del(nxt[x]);q.push(make_pair(a[x],x));
	}
	printf("%d\n",ans);
	return 0;
}
