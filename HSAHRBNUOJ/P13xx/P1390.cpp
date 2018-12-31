#include <cstdio>
#include <algorithm>
#define MAXN 105
#define MAXM 10010
using namespace std;

struct link
{
	int fr, to, val;
};

link e[MAXM];
int n, m, u, v, w, f[MAXN];
int kl, rh, jalor, cnt, fx, fy;

inline bool cmp(link a, link b)
{
	return a.val < b.val;
}

inline int getfather(int x)
{
	return x == f[x] ? x : f[x] = getfather(f[x]);
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		e[i] = (link)
		{
			u, v, w
		};
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		fx = getfather(e[i].fr);
		fy = getfather(e[i].to);
		if (fx != fy)
		{
			f[fy] = fx;
			kl += e[i].val;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	kl *= 7;
	rh = kl / 29;
	kl %= 29;
	jalor = rh / 17;
	rh %= 17;
	if (jalor) printf("%djalor", jalor);
	if (rh) printf("%drh", rh);
	if (kl) printf("%dkl", kl);
	puts("");
	return 0;
}