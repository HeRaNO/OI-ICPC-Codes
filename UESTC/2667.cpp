// By Min_25
// https://min-25.hatenablog.com/entry/2018/05/03/145505
// http://oeis.org/A000328
#include <cstdio>
#include <cmath>

#include <utility>
#include <stack>
#include <functional>

using namespace std;
using i64 = long long;

i64 solve_fast(i64 N) {
  auto inside = [N] (i64 x, i64 y) {
    return x * x + y * y <= N; 
  };
  auto cut = [] (i64 x, i64 y, int dx1, int dy1) {
    return dx1 * x >= dy1 * y;
  };

  const i64 v = sqrtl(N / 2), w = sqrtl(N);
  i64 x = v;
  i64 y = i64(sqrtl(max<i64>(0, N - (v + 1) * (v + 1)))) + 1;

  auto stac = stack< pair<int, int> >({{0, 1}, {1, 1}});

  i64 ret = 0;
  while (1) {
    int dx1, dy1; tie(dx1, dy1) = stac.top(); stac.pop();
    while (inside(x + dx1, y - dy1)) {
      x += dx1; y -= dy1;

      ret += i64(dx1) * (y - 1) 
          + ((i64(dx1 + 1) * (dy1 + 1)) >> 1) - dy1;
    }

    int dx2 = dx1, dy2 = dy1;
    while (!stac.empty()) {
      tie(dx1, dy1) = stac.top();
      if (inside(x + dx1, y - dy1)) break;
      stac.pop();
      dx2 = dx1, dy2 = dy1;
    }
    if (stac.empty()) break;

    while (1) {
      int dx12 = dx1 + dx2, dy12 = dy1 + dy2;
      if (inside(x + dx12, y - dy12)) {
        stac.emplace(dx1 = dx12, dy1 = dy12);
      } else {
        if (cut(x + dx12, y - dy12, dx1, dy1)) break;
        dx2 = dx12, dy2 = dy12;
      }
    }
  }
  ret = ret * 2 + i64(v) * v;
  ret = ret * 4 + 4 * i64(w) + 1;
  return ret;
}

i64 solve_naive(i64 N) {
  int v = (int) sqrtl(N);
  i64 ret = 0;
  for (int i = 1; i <= v; ++i) {
    ret += (int) sqrtl(N - i64(i) * i);
  }
  return 4 * (ret + v) + 1;
}

int main() {
  i64 N;
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &N);
    printf("%lld\n", solve_fast(N * N));
  }
  return 0;
}
