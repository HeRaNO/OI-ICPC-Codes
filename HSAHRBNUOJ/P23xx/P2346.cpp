#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10
#define MAXL 20000
using namespace std;

const int bit[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
struct trans
{
	int status[MAXN], n, m, step, dir;
	bool operator < (const trans &b) const
	{
		for (int i = 0; i < n; i++) if (status[i] != b.status[i]) return status[i] < b.status[i];
		return false;
	}
	bool operator == (const trans &b) const
	{
		for (int i = 0; i < n; i++) if (status[i] != b.status[i]) return false;
		return true;
	}
	trans &operator = (const trans &b)
	{
		n = b.n;
		m = b.m;
		step = b.step;
		dir = b.dir;
		memcpy(status, b.status, n * sizeof(status[0]));
		return *this;
	}
	void swap_row(int r1, int r2)
	{
		swap(status[r1], status[r2]);
		return ;
	}
	void swap_column(int c1, int c2)
	{
		for (int i = 0; i < n; i++)
			if (!(status[i]&bit[c1]) ^ !(status[i]&bit[c2]))
			{
				status[i] ^= bit[c1];
				status[i] ^= bit[c2];
			}
		return ;
	}
	void rev_row(int r)
	{
		int tmp = 0;
		for (int i = 0; i < m; i++)
		{
			tmp <<= 1;
			if (status[r] & 1) tmp++;
			status[r] >>= 1;
		}
		status[r] = tmp;
		return ;
	}
	void rev_column(int c)
	{
		for (int i = (n - 1) >> 1; ~i; i--)
			if (!(status[i]&bit[c]) ^ !(status[n - i - 1]&bit[c]))
			{
				status[i] ^= bit[c];
				status[n - i - 1] ^= bit[c];
			}
		return ;
	}
};

int n, m, ans;
int _1cnt, _1_cnt;
char g[MAXN];
trans src, ter;
set <trans> s;
set <trans> :: iterator it;
trans q[2][MAXL];
int head[2], tail[2], opt;

inline int BFS()
{
	q[0][tail[0]++] = src;
	q[1][tail[1]++] = ter;
	s.insert(src);
	s.insert(ter);
	while (head[0] < tail[0] || head[1] < tail[1])
	{
		opt = (head[0] >= tail[0] || head[1] < tail[1] && tail[0] - head[0] > tail[1] - head[1]);
		int d = q[opt][head[opt]].step;
		while (q[opt][head[opt]].step == d && head[opt] < tail[opt])
		{
			trans u = q[opt][head[opt]++];
			for (int i = 1; i < n; i++)
				for (int j = 0; j < i; j++)
				{
					trans bak = u;
					bak.swap_row(i, j);
					bak.step++;
					it = s.find(bak);
					if (it == s.end())
					{
						s.insert(bak);
						q[opt][tail[opt]++] = bak;
					}
					else if (it->dir != opt) return it->step + bak.step;
				}
			for (int i = 1; i < m; i++)
				for (int j = 0; j < i; j++)
				{
					trans bak = u;
					bak.swap_column(i, j);
					bak.step++;
					it = s.find(bak);
					if (it == s.end())
					{
						s.insert(bak);
						q[opt][tail[opt]++] = bak;
					}
					else if (it->dir != opt) return it->step + bak.step;
				}
			for (int i = 0; i < n; i++)
			{
				trans bak = u;
				bak.rev_row(i);
				bak.step++;
				it = s.find(bak);
				if (it == s.end())
				{
					s.insert(bak);
					q[opt][tail[opt]++] = bak;
				}
				else if (it->dir != opt) return it->step + bak.step;
			}
			for (int i = 0; i < m; i++)
			{
				trans bak = u;
				bak.rev_column(i);
				bak.step++;
				it = s.find(bak);
				if (it == s.end())
				{
					s.insert(bak);
					q[opt][tail[opt]++] = bak;
				}
				else if (it->dir != opt) return it->step + bak.step;
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		src.status[i] = 0;
		scanf("%s", g);
		for (int j = 0; j < m; j++)
		{
			src.status[i] |= ((int)(g[j] - '0') << j);
			_1cnt += (g[j] - '0');
		}
	}
	for (int i = 0; i < n; i++)
	{
		ter.status[i] = 0;
		scanf("%s", g);
		for (int j = 0; j < m; j++)
		{
			ter.status[i] |= ((int)(g[j] - '0') << j);
			_1_cnt += (g[j] - '0');
		}
	}
	if (_1cnt != _1_cnt)
	{
		puts("No solution!");
		return 0;
	}
	src.n = ter.n = n;
	src.m = ter.m = m;
	src.dir = 0;
	ter.dir = 1;
	src.step = ter.step = 0;
	if (src == ter)
	{
		puts("0");
		return 0;
	}
	ans = BFS();
	if (ans == -1)
	{
		puts("No solution!");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}
