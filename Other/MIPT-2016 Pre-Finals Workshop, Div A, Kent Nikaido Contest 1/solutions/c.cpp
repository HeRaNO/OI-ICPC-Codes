#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define drep(i,n) for (int i = n-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

const int MX = 100005;

int main() {
  int n = 7;
  vl a(n);
  rep(i,n) cin >> a[i];
  if (!a[0]) {
    puts("NO");
    return 0;
  }
  a[0]--;
  vl b(n);
  rep(i,n) {
    ll s = 0;
    rep(j,n) {
      int h = 1;
      if (j&1) h = -1;
      s += a[(i+j+1)%n]*h;
    }
    if (s < 0) {
      puts("NO");
      return 0;
    }
    b[i] = s;
  }
  rep(i,n) {
    if (!b[i]) break;
    b[i] = -1;
  }
  drep(i,n) {
    if (!b[i]) break;
    b[i] = -1;
  }
  rep(i,n) if (b[i] > 0) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
