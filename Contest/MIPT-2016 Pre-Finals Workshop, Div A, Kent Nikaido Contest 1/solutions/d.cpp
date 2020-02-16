#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
inline int in() { int x; scanf("%d", &x); return x; }
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 500005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

int n, m;
vi to[MX];
int deg[MX];

// Union find
struct uf{
	vector<int> d;
	uf(){}
	uf(int mx):d(mx,-1){}
	int root(int x){
		if(d[x] < 0) return x;
		return d[x] = root(d[x]);
	}
	void unite(int x, int y){
		x = root(x); y = root(y);
		if(x == y) return;
		if(d[x] > d[y]) swap(x,y);
		if(d[x] == d[y]) d[x]--;
		d[y] = x;
	}
};
//

// Mod int
const int mod = 1000000007;
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x((x%mod+mod)%mod){}
	mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
	mint operator+(const mint& a)const{ return mint(*this) += a;}
	mint operator-(const mint& a)const{ return mint(*this) -= a;}
	mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
//
mint x2[MX];

int odd[MX], dep[MX];
int dfs(int v, int ndep=0, int p=-1) {
  dep[v] = ndep;
  odd[v] = 0;
  if (deg[v]&1) odd[v]++;
  for (int u : to[v]) {
    if (u == p) continue;
    odd[v] += dfs(u,ndep+1,v);
  }
  return odd[v];
}

int main(){
  scanf("%d%d",&n,&m);
  vector<P> e;
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    a--; b--;
    e.pb({a,b});
    deg[a]++; deg[b]++;
  }
  x2[0] = 1;
  rep(i,m) x2[i+1] = x2[i]*2;
  mint ans = 0;
  rep(i,m) ans += x2[i+1];
  uf t(MX);
  vi es;
  rep(i,e.size()) {
    int a = e[i].fi, b = e[i].se;
    if (t.root(a) == t.root(b)) continue;
    t.unite(a,b);
    to[a].pb(b);
    to[b].pb(a);
    es.pb(i);
    ans += x2[i+1];
  }
  dfs(0);
  rep(i,es.size()) {
    int ei = es[i];
    int a = e[ei].fi, b = e[ei].se;
    if (dep[a] < dep[b]) a = b;
    if (odd[a]%2 == 0) ans -= x2[ei+1]; 
  }
  cout << ans.x << endl;
  return 0;
}





