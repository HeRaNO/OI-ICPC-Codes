#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, x, y) for (int i = x; i <= y; ++i)
#define dwn(i, x, y) for (int i = x; i >= y; --i)
#define pu {temp = encode(tot); if (!vis[temp]) {vis[temp] = true; q[++tl] = temp; dist[tl] = dist[hd] + 1;}}
#define INF 1 << 30

using namespace std;

const int maxs = 1 << 20;
int T, n;
int vis[maxs], dist[maxs];
int inp[32];
int dd[15], cnt[15];

inline int encode(int *p)
{
	int r = 0;
	rep(i, 0, 14) r += p[i] * dd[i];
	return r;
}
inline void decode(int x, int *p)
{
	dwn(i, 14, 0)
	{
		p[i] = x / dd[i];
		x %= dd[i];
	}
}
inline void calcu()
{
	dd[0] = 1;
	rep(i, 1, 14) dd[i] = cnt[i - 1] * dd[i - 1];
}
int q[maxs << 1];
int temp;
inline int bfs(int x)
{
	memset(vis, 0, sizeof(vis));
	int tot[15];
	int hd, tl;
	q[hd = tl = 0] = x;
	int s;
	int ans = INF;
	dist[0] = 0;
	while (hd <= tl)
	{
		s = q[hd];
		if (s == 0)
		{
			ans = min(ans, dist[hd]);
			++hd;
			continue;
		}
		//        vis[s] = true;
		decode(s, tot);
		bool f = false;
		int ccnt = 0;
		if (tot[13] && tot[14])
		{
			tot[13] = tot[14] = 0;
			f = true;
			pu
			tot[13] = tot[14] = 1;
		}
		rep(i, 0, 14)
		{
			if (tot[i]) ++ccnt;
			if (tot[i] >= 4)
			{
				tot[i] -= 4;
				f = true;
				pu
				rep(j, 0, 14) if (tot[j])
				{
					--tot[j];
					rep(k, 0, 14) if (tot[k])
					{
						--tot[k];
						f = true;
						pu
						++tot[k];
					}
					++tot[j];
				}
				rep(j, 0, 14) if (tot[j] >= 2)
				{
					tot[j] -= 2;
					rep(k, 0, 14) if (tot[k] >= 2)
					{
						tot[k] -= 2;
						f = true;
						pu
						tot[k] += 2;
					}
					tot[j] += 2;
				}
				tot[i] += 4;
			}//zhadan and sidaier
			if (tot[i] >= 2)
			{
				tot[i] -= 2;
				f = true;
				pu
				tot[i] += 2;
			}//duizi
			if (tot[i] >= 3)
			{
				tot[i] -= 3;
				f = true;
				pu
				rep(j, 0, 14)
				{
					if (i == j) continue;
					if (tot[j] >= 1)
					{
						--tot[j];
						f = true;
						pu
						++tot[j];
					}//sandaiyi
					if (tot[j] >= 2)
					{
						tot[j] -= 2;
						f = true;
						pu
						tot[j] += 2;
					}//sandaier
				}
				tot[i] += 3;
			}//sanzhang and sandaiyi, sandaier
		}
		int lianxu;
		rep(i, 0, 7)
		{
			lianxu = 0;
			rep(j, i, 11) if (tot[j] >= 1) ++lianxu;
			else break;
			if (lianxu >= 5)
			{
				rep(j, i, i + 3) --tot[j];
				rep(j, i + 4, i + lianxu - 1)
				{
					--tot[j];
					f = true;
					pu
				}
				rep(j, i, i + lianxu - 1) ++tot[j];
			}
		}//danshunzi
		rep(i, 0, 9)
		{
			lianxu = 0;
			rep(j, i, 11) if (tot[j] >= 2) ++lianxu;
			else break;
			if (lianxu >= 3)
			{
				rep(j, i, i + 1) tot[j] -= 2;
				rep(j, i + 2, i + lianxu - 1)
				{
					tot[j] -= 2;
					f = true;
					pu
				}
				rep(j, i, i + lianxu - 1) tot[j] += 2;
			}
		}//shuangshunzi
		rep(i, 0, 10)
		{
			lianxu = 0;
			rep(j, i, 11) if (tot[j] >= 3) ++lianxu;
			else break;
			if (lianxu >= 2)
			{
				tot[i] -= 3;
				rep(j, i + 1, i + lianxu - 1)
				{
					tot[j] -= 3;
					f = true;
					pu
				}
				rep(j, i, i + lianxu - 1) tot[j] += 3;
			}
		}//sanshunzi
		if (!f) ans = min(ans, dist[hd] + ccnt);
		++hd;
	}
	return ans;
}
int xx, yy;
inline void work()
{
	memset(cnt, 0, sizeof(cnt));
	rep(i, 1, n)
	{
		scanf("%d %d", &xx, &yy);
		if (3 <= xx && xx <= 13) inp[i] = xx - 3;
		if (xx == 1) inp[i] = 11;
		if (xx == 2) inp[i] = 12;
		if (xx == 0 && yy == 1) inp[i] = 13;
		if (xx == 0 && yy == 2) inp[i] = 14;
		++cnt[inp[i]];
	}
	rep(i, 0, 14) ++cnt[i];
	calcu();
	rep(i, 0, 14) --cnt[i];
	printf("%d\n", bfs(encode(cnt)));
}
int main()
{
	scanf("%d %d", &T, &n);
	while (T--) work();
	return 0;
}
