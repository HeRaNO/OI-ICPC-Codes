#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 35, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Max flow
// BFS
// Graph
typedef int TT;
struct edge{
	int next, to, lim;
	TT co;
	edge(){}
	edge(int next, int to, TT co=0, int lim=1):next(next),to(to),co(co),lim(lim){}
};
struct graph{
	vector<TT> head; vector<edge> e; int es, vs;
	graph(){}
	graph(int vsz, int esz){ head.resize(vsz); e.resize(esz+1); init(vsz);}
	void init(int vsz){ es = 0; vs = vsz; rep(i,vsz) head[i] = -1;}
	void add(int from, int to, TT co=0, int lim=1){ e[es] = edge(head[from],to,co,lim); head[from] = es++;}
	void add2(int from, int to, TT co=0, int lim=1){ add(from,to,co,lim); add(to,from,co,lim);}
	void addf(int from, int to, TT co=0, int lim=1){ add(from,to,co,lim); add(to,from,-co,0);}
};
//
vector<int> dist, prev;
void bfs(graph& ng, int sv, vector<int>& ndist){
	ndist.resize(ng.vs); fill(rng(ndist),INF); prev.resize(ng.vs); fill(rng(prev),-1);
	queue<int> q;
	int v, e; ng.e[ng.es].to = sv; ndist[sv] = 0; q.push(ng.es);
	while(!q.empty()){
		e = q.front(); q.pop(); v = ng.e[e].to;
		if(prev[v] != -1) continue;
		prev[v] = e^1;
		for(int i = ng.head[v]; i != -1; i = ng.e[i].next)
			if(ng.e[i].lim > 0 && ndist[ng.e[i].to] == INF){
				ndist[ng.e[i].to] = ndist[v]+1; q.push(i);}
	}
}
//
vector<int> it;
TT dfs(graph& ng, int v, int tv, TT nf=INF){
	if(v == tv) return nf;
	for(; it[v] != -1; it[v] = ng.e[it[v]].next){
		int u = ng.e[it[v]].to; TT f;
		if(!ng.e[it[v]].lim || dist[v] >= dist[u]) continue;
		if(f = dfs(ng,u,tv,min(nf,ng.e[it[v]].lim))){
			ng.e[it[v]].lim -= f;
			ng.e[it[v]^1].lim += f;
			return f;
		}
	}
	return 0;
}
TT maxflow(graph& ng, int sv, int tv){
	it.resize(ng.vs);
	TT flow = 0;
	while(1){
		bfs(ng,sv,dist);
		if(dist[tv] == INF) return flow;
		rep(i,ng.vs) it[i] = ng.head[i];
		TT f;
		while(f = dfs(ng,sv,tv)) flow += f;
	}
}
//

int n, m;
string in[MX];
char f[MX][MX];
int id[MX][MX];

void cnct(graph& g, int i, int j, int ni, int nj){
	if(ni<0||nj<0||ni>=n-1||nj>=n-1) return;
	g.addf(id[i][j],id[ni][nj]);
}

int main(){
	cin >> m;
	rep(i,m) cin >> in[i];
	n=m+2;
	rep(i,n)rep(j,n) f[i][j] = 'x';
	rrep(i,m)rrep(j,m) f[i][j] = in[i-1][j-1];
	rep(i,n-1)rep(j,n-1) id[i][j] = i*(n-1)+j;
	
	int sv = (n-1)*(n-1), tv = sv+1, mx = 0;
	graph g(n*n,n*n*6);
	rep(i,n-1)rep(j,n-1){
		int cnt = 0;
		rep(v,4) cnt += (f[i+v/2][j+v%2] == 'x');
		if(cnt == 4) continue;
		mx++;
		if(i+j&1) g.addf(sv,id[i][j],0,2); else g.addf(id[i][j],tv,0,2);
		if(!(i+j&1)) continue;
		if(f[i][j]!=f[i+1][j]) cnct(g,i,j,i,j-1);
		if(f[i][j]!=f[i][j+1]) cnct(g,i,j,i-1,j);
		if(f[i+1][j+1]!=f[i+1][j]) cnct(g,i,j,i+1,j);
		if(f[i+1][j+1]!=f[i][j+1]) cnct(g,i,j,i,j+1);
	}
	
	if(maxflow(g,sv,tv) == mx) puts("YES"); else puts("NO");
	
	return 0;
}





