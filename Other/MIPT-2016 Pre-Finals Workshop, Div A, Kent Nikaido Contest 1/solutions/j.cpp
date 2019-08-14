#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define df(x) int x = in()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
using namespace std;
typedef vector<int> vi;
inline int in() { int x; scanf("%d", &x); return x;}

const int MX = 100005;

int main() {
  df(n);
  vi s(n), t(n);
  rep(i,n) s[i] = in(), t[i] = in();
  vi x(MX);
  rep(i,n) x[s[i]]++, x[t[i]]--;
  rep(i,MX-1) x[i+1] += x[i];
  int mx = 0;
  rep(i,MX) maxs(mx,x[i]);
  int l = MX, r = 0;
  rep(i,MX) if (x[i] == mx) mins(l,i);
  rep(i,MX) if (x[i] == mx) maxs(r,i);
  int ans = mx;
  rep(i,n) if (s[i] <= l && r < t[i]) ans = mx-1;
  cout << ans << endl;
  return 0;
}
