//Decision's template
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<ctime>
using namespace std;
#define DP_maxn 16
#define maxn 50005
#define INF 1e18
#define mod 1000000007
#define mst(s,k) memset(s,k,sizeof(s))
typedef long long ll;
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
/*-------------------------------template End--------------------------------*/

struct node{
	int l,r,x,mx;
};

int l,r;
int bin[20],Log[maxn];
int n,m,cnt,ind,sum;
int root;
int siz[maxn],f[maxn],dis[maxn];
int val[2000005],mx[2000005][22];
pair<int,int> p[2000005];
bool vis[maxn];
priority_queue<node,vector<node> >q;
vector<Edge> G;
vector<int> edges[maxn];

bool operator < (node a,node b){
	return val[a.mx] + val[a.x] < val[b.mx] + val[b.x];
}

void Addedge(int u,int v,int d){
	G.push_back(Edge(u,v,d));
	G.push_back(Edge(v,u,d));
	edges[u].push_back(G.size() - 2);
	edges[v].push_back(G.size() - 1);
}

void getroot(int u,int fa){
	siz[u] = 1;f[u] = 0;
	int len = edges[u].size();
	for(int i = 0;i < len;i++){
		int v =G[edges[u][i]].to;
		if(v == fa || vis[v]) continue;
		getroot(v,u);
		siz[u] += siz[v];
		f[u] = max(f[u],siz[v]);
	}
	f[u] = max(f[u],sum - siz[u]);
	if(!root || f[u] < f[root]) root = u;
}

void getdis(int u,int fa){
	val[++ind] = dis[u];
	p[ind] = make_pair(l,r);
	int len = edges[u].size();
	for(int i = 0; i < len;i++){
		int v = G[edges[u][i]].to;
		if(v != fa && !vis[v]){
		    dis[v] = dis[u] + G[edges[u][i]].dist;
		    getdis(v,u);
		}
	}
}

void solve(int u){
	val[++ind] = 0;
	p[ind] = make_pair(0,0);
	vis[u] = 1;
	l = r = ind;
	int len = edges[u].size();
	for(int i = 0;i < len;i++){
		int v = G[edges[u][i]].to;
		if(!vis[v]){
			dis[v] = G[edges[u][i]].dist;
			getdis(v,u);
			r = ind;
		}
	}
	for(int i = 0;i < len;i++){
		int v = G[edges[u][i]].to;
		if(!vis[v]){
			sum = siz[v];
			root = 0;
			getroot(v,u);
			solve(root);
		}
	}
}

void pre(){
	bin[0]=1;
	for(int i=1;i<20;i++) bin[i]=bin[i-1]<<1;
	Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
	for(int i=1;i<=ind;i++) mx[i][0]=i;
	for(int i=1;i<=Log[n];i++){
		for(int j=1;j<=ind;j++){
			if(j+bin[i]<=ind){
				int t1=mx[j][i-1],t2=mx[j+bin[i-1]][i-1];
				if(val[t1]>val[t2])mx[j][i]=t1;
				else mx[j][i]=t2;
			}
        }
    }
}

int query(int x,int y){
	if(x==y)return x;
	int t=Log[y-x+1];
	int t1=mx[x][t],t2=mx[y-bin[t]+1][t];
	if(val[t1]>val[t2])return t1;
	return t2;
}

void push(int l,int r,int x)
{
	q.push((node){l,r,x,query(l,r)});
}

int main(){
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i = 1;i < n;i++){
		scanf("%d%d%d",&u,&v,&w);
		Addedge(u,v,w);
	}
	sum = n;
	f[0] = n;
	getroot(1,0);
	solve(root);
	pre();	
	for(int i = 1;i <= ind;i++){
		int l = p[i].first,r = p[i].second;
		if(l) push(l,r,i);
	}
	while(m --){
		node t = q.top();
		q.pop();
		printf("%d\n",val[t.mx] + val[t.x]);
		if(t.mx+1<=t.r)push(t.mx+1,t.r,t.x);
		if(t.mx-1>=t.l)push(t.l,t.mx-1,t.x);
	}
	return 0;
}