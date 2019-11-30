#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int P=1e5;
const long long M=1e9+7;

struct link{int to,nxt;};

struct F
{
	int l,x,p;
	F(){}
	F(int _,int __,int ___):l(_),x(__),p(___){}
	bool operator < (const F &a)const{
		return l<a.l;
	}
};

F a[MAXN<<1];
link e[MAXN<<1];
int head[MAXN],ecnt;
int n,R,l,r,mxr,SIZE,G,siz[MAXN],mx[MAXN],f[MAXN];
int pt[MAXN],lg[MAXN<<1],dep[MAXN],dis[18][MAXN<<1];
long long inv[MAXN],w[MAXN],ans,c=1,cnt;
long long fw[MAXN],fwd[MAXN],gw[MAXN],gwd[MAXN];
bool vis[MAXN];

inline void addedge(int u,int v)
{
	e[ecnt]=(link){v,head[u]};head[u]=ecnt++;
	e[ecnt]=(link){u,head[v]};head[v]=ecnt++;
}

inline void DFS_size_and_G(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa&&!vis[e[i].to])
		{
			DFS_size_and_G(e[i].to,x);
			siz[x]+=siz[e[i].to];
			mx[x]=max(mx[x],siz[e[i].to]);
		}
	mx[x]=max(mx[x],SIZE-siz[x]);
	if (mx[x]<mx[G]) G=x;
	return ;
}

inline void TreeDC(int x)
{
	vis[x]=true;
	for(int i=head[x];~i;i=e[i].nxt)
		if(!vis[e[i].to])
		{
			mx[0]=SIZE=siz[e[i].to];G=0;
			DFS_size_and_G(e[i].to,x);
			f[G]=x;TreeDC(G);
		}
	vis[x]=false;
	return ;
}

inline void dfs(int x,int f)
{
	dis[0][++R]=dep[x];pt[x]=R;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
			dis[0][++R]=dep[x];
		}
	return ;
}

inline int getdis(int x,int y)
{
	int d=dep[x]+dep[y];
	x=pt[x];y=pt[y];
	if (x>y) swap(x,y);
	int t=lg[y-x+1];
	return d-2*min(dis[t][x],dis[t][y-(1<<t)+1]);
}

inline void add(int x)
{
	(cnt+=w[x]*fwd[x]%M)%=M;(fw[x]+=w[x])%=M;
	for (int i=x;f[i];i=f[i])
	{
		int d=getdis(f[i],x);
		cnt+=(d*w[x]%M)*((fw[f[i]]-gw[i]+M)%M)%M+w[x]*((fwd[f[i]]-gwd[i]+M)%M)%M;
		cnt%=M;
		(fw[f[i]]+=w[x])%=M;(gw[i]+=w[x])%=M;
		(fwd[f[i]]+=w[x]*d%M)%=M;(gwd[i]+=w[x]*d%M)%=M;
	}
	return ;
}

inline void del(int x)
{
	cnt=(cnt-w[x]*fwd[x]%M+M)%M;fw[x]=(fw[x]-w[x]+M)%M;
	for (int i=x;f[i];i=f[i])
	{
		int d=getdis(f[i],x);
		fw[f[i]]=(fw[f[i]]-w[x]+M)%M;gw[i]=(gw[i]-w[x]+M)%M;
		fwd[f[i]]=(fwd[f[i]]-w[x]*d%M+M)%M;gwd[i]=(gwd[i]-w[x]*d%M+M)%M;
		cnt-=((d*w[x]%M)*((fw[f[i]]-gw[i]+M)%M)%M+w[x]*((fwd[f[i]]-gwd[i]+M)%M)%M)%M;
		(cnt+=M)%=M;
	}
	return ;
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
	memset(head,-1,sizeof head);inv[1]=1;
	for (int i=2;i<=P;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	read(n);
	for (int i=1,p=1;i<=n;i++,p+=2)
	{
		read(l);read(r);(c*=(r-l+1))%=M;w[i]=inv[r-l+1];
		a[p]=F(l,0,i);a[i<<1]=F(r+1,1,i);
		mxr=max(r,mxr);
	}
	sort(a+1,a+(n<<1)+1);
	for (int i=1;i<n;i++) read(l),read(r),addedge(l,r);
	dfs(1,-1);
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
			dis[j][i]=min(dis[j-1][i],dis[j-1][i+(1<<(j-1))]);
	SIZE=mx[0]=n;DFS_size_and_G(1,-1);TreeDC(G);
	for (int i=1,j=0;i<=mxr;i++)
	{
		while (j<(n<<1)&&a[j+1].l==i)
		{
			++j;
			if (a[j].x) del(a[j].p);
			else add(a[j].p);
		}
		(ans+=cnt)%=M;
	}
	printf("%lld\n",ans*c%M);
	return 0;
}
