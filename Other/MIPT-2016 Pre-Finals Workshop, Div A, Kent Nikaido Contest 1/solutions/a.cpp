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

const int MX = 55, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,-1,1,1}, dy[] = {-1,1,1,-1};

string s[MX];

// (odd,odd) : s
// (even,even) : t

// binary matching
struct match {
	vector<bool> used;
	vector<vector<int> > to;
	vector<int> p;
	int n, m;
	match(int n, int m):used(n),to(n),p(m),n(n),m(m){}
	bool dfs(int v){
		if(used[v]) return false;
		used[v] = true;
		rep(i,to[v].size()) {
			int u = to[v][i];
			if (p[u] == -1 || dfs(p[u])){
				p[u] = v;
				return true;
			}
		}
		return false;
	}
    
	int solve(){
		int res = 0;
		rep(i,m) p[i] = -1;
		rep(i,n) {
			rep(j,n) used[j] = false;
			if(dfs(i)) ++res;
		}
		return res;
	}
};
//

map<P,int> np, mp;
int si[MX*MX], sj[MX*MX];
int ti[MX*MX], tj[MX*MX];

int main(){
	int n;
	cin >> n;
	rep(i,n) cin >> s[i];
	
	rep(i,n)rep(j,n){
		if((i+j&1) || s[i][j] == '.') continue;
		if(i&1){
			si[sz(np)] = i;
			sj[sz(np)] = j;
			np[P(i,j)] = sz(np)-1;
		} else {
			ti[sz(mp)] = i;
			tj[sz(mp)] = j;
			mp[P(i,j)] = sz(mp)-1;
		}
	}
	
	match bm(sz(np),sz(mp));
	
	rep(i,n)rep(j,n){
		if(!(i&1) || !(j&1) || s[i][j] == '.') continue;
		rep(v,4){
			int ni = i+dx[v], nj = j+dy[v];
			if(ni<0||nj<0||ni>=n||nj>=n||s[ni][nj]=='.') continue;
			bm.to[np[P(i,j)]].pb(mp[P(ni,nj)]);
		}
	}
	
	bm.solve();
	
	int ans = 0;
	rep(i,bm.m){
		int mi = ti[i], mj = tj[i];
		int ni = si[bm.p[i]], nj = sj[bm.p[i]];
		ans += (mi-ni+mj-nj)/2;
	}
	
	cout << (ans&1) << endl;
	
	return 0;
}





