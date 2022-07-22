#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 10;

// void Update()

int n;

struct Tree1 {
	long long a[N << 2], maxv[N << 2], lazy[N << 2];

	void Push_down(int o) {
		if (lazy[o]) {
			lazy[o << 1] += lazy[o];
			lazy[o << 1 | 1] += lazy[o];
			maxv[o << 1] += lazy[o];
			maxv[o << 1 | 1] += lazy[o];
			lazy[o] = 0;
		}
	}

	void Push_up(int o) {
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	void Update(int o, int L, int R, int l, int r, long long v) {
		if (l > r)	return;
		if (l <= L && R <= r) {
			lazy[o] += v;
			maxv[o] += v;
			return;
		}
		Push_down(o);
		int M = (L + R) >> 1;
		if (l <= M)	Update(o << 1, L, M, l, r, v);
		if (r > M)	Update(o << 1 | 1, M + 1, R, l, r, v);
		Push_up(o);
	}

	long long Query_max(int o, int L, int R, int l, int r) {
		if (l > r)	return 0;
		if (l <= L && R <= r)	return maxv[o];
		Push_down(o);
		long long res = 0;
		int M = (L + R) >> 1;
		if (l <= M)	res = max(res, Query_max(o << 1, L, M, l, r));
		if (r > M)	res = max(res, Query_max(o << 1 | 1, M + 1, R, l, r));
		Push_up(o);
		return res;
	}
}T1, T2;

struct Node {
	int l, r, a, w;
	bool operator < (const Node &tmp) const { return r < tmp.r; }
}node[N];

int work() {
	vector <int> a;
	a.push_back(0);
	a.push_back(-1);
	for (int i = 1; i <= n; i++) {
		a.push_back(node[i].l);
		a.push_back(node[i].r);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i = 1; i <= n; i++) {
		node[i].l = lower_bound(a.begin(), a.end(), node[i].l) - a.begin() + 1;
		node[i].r = lower_bound(a.begin(), a.end(), node[i].r) - a.begin() + 1;
	}
	return a.size();
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	scanf("%d %d %d %d", &node[i].l, &node[i].r, &node[i].a, &node[i].w);
	sort(node + 1, node + 1 + n);
	int m = work();
	int pos = 1;
	long long now = 0;
	set <pair<int, pair<int, int>>> st;	st.insert(make_pair(0, make_pair(1, m)));
	for (int i = 1; i <= m; i++) {	
		while (pos <= n && node[pos].r <= i) {
			if (node[pos].a) {
				T1.Update(1, 1, m, 1, node[pos].l - 1, node[pos].w);
			}
			else {
				auto it = st.lower_bound(make_pair(-node[pos].w, make_pair(0, 0)));
				int L = (it -> second).first, R = node[pos].l - 1;
				if (it != st.end()) {
					while (it != st.end()) {
						int l1 = (it -> second).first, r1 = (it -> second).second, w1 = it -> first;
						if (l1 > R)	break;
						T2.Update(1, 1, m, l1, min(r1, R), node[pos].w + w1);
						auto it2 = it;
						it++;
						st.erase(it2);
						if (r1 > R)	st.insert(make_pair(w1, make_pair(R + 1, r1)));
					}
					st.insert(make_pair(-node[pos].w, make_pair(L, R)));
				}
			}
			pos++;
		}
		long long now1 = T1.Query_max(1, 1, m, 1, i - 1), now2 = T2.Query_max(1, 1, m, 1, i - 1);
		now = max(now1, now2);
		T1.Update(1, 1, m, i, i, now);
		T2.Update(1, 1, m, i, i, now);
	}
	printf("%lld\n", now);
	return 0;
}