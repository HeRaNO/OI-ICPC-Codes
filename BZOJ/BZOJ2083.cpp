#include <cstdio>
#include <vector>
#define MAXN 1000005
using namespace std;

int n, m, l, now;
int a[MAXN], b[MAXN];
vector<int> table[MAXN];
bool r;

inline int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int binary(int l, int t)
{
	int left = 0, right = table[t].size() - 1, middle, ans = m + 1;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (table[t][middle] > now) ans = middle, right = middle - 1;
		else left = middle + 1;
	}
	if (ans == m + 1) return ans;
	return table[t][ans];
}

int main()
{
	m = read();
	for (int i = 1; i <= m; i++) table[read()].push_back(i);
	n = read();
	while (n--)
	{
		l = read();
		r = true;
		now = 0;
		for (int i = 1; i <= l; i++)
		{
			now = binary(now, read());
			if (!r) continue;
			if (now > m) r = false;
		}
		if (!r) puts("NIE");
		else puts("TAK");
	}
	return 0;
}