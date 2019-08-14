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
inline int in() { int x; scanf("%d",&x); return x;}
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

int a[MX];
ll ans;
set<int> d;

void del(int p) {
  auto it = d.find(p);
  int ph = 1, h = (p&1?0:1);
  auto jt = it;
  if (jt != d.begin()) {
    --jt;
    int q = *jt;
    ph = (q&1?0:1);
  }
  ans -= a[p]*ph;
  ans += a[p]*h;
  jt = it; ++jt;
  if (jt != d.end()) {
    int q = *jt;
    ans -= a[q]*h;
    ans += a[q]*ph;
  }
  d.erase(it);
}
void add(int p) {
  int i;
  auto it = d.upper_bound(p);
  if (it != d.end() && a[(*it)] <= a[p]) return;
  int ph = 1, h = (p&1?0:1);
  if (it != d.begin()) {
    auto jt = it;
    --jt;
    ph = ((*jt)&1?0:1);
  }
  ans += a[p]*ph;
  ans -= a[p]*h;
  if (it != d.end()) {
    int q = *it;
    ans += a[q]*h;
    ans -= a[q]*ph;
  }
  d.insert(p);
  while (1) {
    it = d.find(p);
    if (it != d.begin()) {
      --it;
      if (a[*it] >= a[p]) {
        del(*it);
        continue;
      }
    }
    break;
  }
}

int main(){
  int n, q;
  scanf("%d",&n);
  rep(i,n) scanf("%d",&a[i]);
  int l = INF;
  drep(i,n) {
    int h = (i&1?0:1);
    if (l <= a[i]) {
      ans += a[i]*h;
    } else {
      l = a[i];
      d.insert(i);
    }
  }
  int ph = 1;
  for(int p : d) {
    int h = (p&1?0:1);
    ans += a[p]*ph;
    ph = h;
  }
  printf("%lld\n",ans);
  scanf("%d",&q);
  rep(qi,q) {
    int p, x;
    scanf("%d%d",&p,&x);
    p--;
    if (d.count(p)) del(p);
    int h = (p&1?0:1);
    ans -= a[p]*h;
    a[p] -= x;
    ans += a[p]*h;
    add(p);
    printf("%lld\n",ans);
  }
  return 0;
}



