//Just a templet,please do not compile it!
#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define MAXT 100010
using namespace std;

struct Modui
{
	int l, r, id, ans;
};

Modui ans[MAXT];
int pos[MAXN];

bool cmp(Modui a, Modui b)
{
	return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}
bool cmp_id(Modui a, Modui b)
{
	return a.id < b.id;
}

inline void update(int x, int v)
{
}

inline int Query()
{
}

inline void ModuiAlgorithm()
{
	sort(ans + 1, ans + T + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= T; i++)
	{
		while (r < ans[i].r) update(++r, 1);
		while (r > ans[i].r) update(r--, -1);
		while (l < ans[i].l) update(l++, -1);
		while (l > ans[i].l) update(--l, 1);
		ans[i].res = Query();
	}
	sort(ans + 1, ans + T + 1, cmp_id);
	return ;
}

int main()
{
	block_num = (int)sqrt(n);
	for (int i = 1; i <= n; i++) pos[i] = (i - 1) / block_num + 1;
	ModuiAlgorithm();
	return 0;
}
