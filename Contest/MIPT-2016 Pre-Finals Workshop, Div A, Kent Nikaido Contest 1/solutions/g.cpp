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
#include <numeric>
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
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

// Mod int
const int mod = 1000000007;
struct mint;
mint ex(mint a, ll tms);
struct mint{
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator/=(const mint& a){ (x*=ex(a,mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint a, ll tms){
  if(!tms) return 1;
  mint res = ex(a,tms/2);
  res *= res;
  return (tms&1)?res*a:res;
}
//

// direction
// w/r r\w r/w w\r
//  0   1   2   3

int h, w, n;
set<int> row[MX];
set<int> col[MX];
vector<P> tile[MX];

mint solveA(int f) {
  vi lt(h), rt(h);
  vi lb(h), rb(h);
  {
    int l = 1, r = w-1;
    rep(i,h) {
      for (P p : tile[i]) {
        int c = p.fi, d = p.se^f;
        if (d == 0) mins(r,c);
        else if (d == 3) maxs(l,c+1);
        else r = 0;
      }
      lt[i] = l;
      rt[i] = r;
    }
  }
  {
    int l = 1, r = w-1;
    drep(i,h) {
      for (P p : tile[i]) {
        int c = p.fi, d = p.se^f;
        if (d == 1) mins(r,c);
        else if (d == 2) maxs(l,c+1);
        else r = 0;
      }
      lb[i] = l;
      rb[i] = r;
    }
  }
  mint res = 0;
  rep(i,h-1) {
    int l = max(lt[i],lb[i+1]);
    int r = min(rt[i],rb[i+1]);
    res += max(0,r-l+1);
  }
  // cout << res.x << endl;
  return res;
}

mint solveBC(set<int> s[], int m, int mask) {
  rep(i,m) if (sz(s[i]) >= 2) return 0;
  int f = 0;
  rep(i,m) for (int x : s[i]) f |= 1<<x;
  if ((f&mask) != f && (f&(mask^15)) != f) return 0;
  int cnt = 0;
  rep(i,m) if (sz(s[i]) == 0) cnt++;
  // cout << mask << " " << ex(2,cnt).x << endl;
  return ex(2,cnt);
}

mint solveD(set<int> s[], int m) {
  rep(i,m) if (sz(s[i]) >= 2) return 0;
  int f = 0;
  rep(i,m) for (int x : s[i]) f |= 1<<x;
  if (pcnt(f) != 1) return 0;
  return 1;
}

int main() {
  scanf("%d%d%d",&h,&w,&n);

  if (n == 0) {
    mint ans = 0;
    ans += ex(2,h);
    ans += ex(2,w);
    ans -= 2;
    ans += mint(h-1)*(w-1);
    ans *= 2;
    cout << ans.x << endl;
    return 0;
  }

  rep(i,n) {
    int r, c, d;
    scanf("%d%d%d",&r,&c,&d);
    --r; --c; --d;
    int p = (r+c)%2;
    row[r].insert(d^(p<<1));
    col[c].insert(d^(p<<1));
    tile[r].pb(P(c,d^(p<<1)));
  }

  mint ans = 0;
  ans += solveA(0);
  ans += solveA(2);
  ans += solveBC(row,h,(1<<0)|(1<<1));
  ans += solveBC(col,w,(1<<0)|(1<<3));
  ans -= solveD(row,h);
  cout << ans.x << endl;
  return 0;
}





