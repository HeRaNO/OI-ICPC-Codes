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
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 2000005, INF = 1000010000;
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

mint tri[MX], fact[MX];
void init(int n) {
  tri[0] = 1;
  rrep(i,n) tri[i] = tri[i-1]*ex(i,i);
  fact[0] = 1;
  rrep(i,n) fact[i] = fact[i-1]*i;
}
mint getTri(int top, int row) {
  mint x = tri[top+row-1];
  mint y = tri[top-1] * ex(fact[top+row-1]/fact[top-1], top-1);
  return x/y;
}
mint getRect(int top, int a, int b) {
  if (!a || !b) return 1;
  mint x = getTri(top, a+b-1);
  mint y = getTri(top+a, b-1) * getTri(top+b, a-1);
  return x/y;
}

int main(){
  init(MX-3);
  int t;
  scanf("%d",&t);
  rep(ti,t) {
    int a, b, c, d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    a = a-b+1; c = c-d+1;
    if (P(a,b) > P(c,d)) {
      swap(a,c);
      swap(b,d);
    }
    maxs(b,d);
    mint x = fact[a*b+c*d-a*d];
    mint y = getRect((c-a)+(b-d)+1, a, d);
    y *= getRect(1, a, b-d);
    y *= getRect(1, c-a, d);
    printf("%lld\n", (x/y).x);
  }
  return 0;
}





