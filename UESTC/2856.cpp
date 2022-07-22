#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
#define MAXN 205

const int M = 998244353;

void fadd(int &x, int y){ x += y; if (x >= M) x -= M; return ; }

struct Matrix
{
	int m[MAXN][MAXN]; int n;
	Matrix operator * (const Matrix &a) const {
		Matrix res;res.n=n;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
			{
				res.m[i][j] = 0;
				for (int k = 0; k <= n; k++)
					fadd(res.m[i][j], 1LL * m[i][k] * a.m[k][j] % M);
			}
		return res;
	}
}r, b;

char s[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int L = strlen(s);
	std::vector<int> a(L);
	for (int i = 0; i < L; i++)
	{
		if ('0' <= s[i] && s[i] <= '9') a[i] = s[i] - '0';
		if ('A' <= s[i] && s[i] <= 'Z') a[i] = s[i] - 'A' + 10;
		if ('a' <= s[i] && s[i] <= 'z') a[i] = s[i] - 'a' + 36;
	}
	std::vector<int> nxt(L + 1);
	std::function<void()> GetNext = [&]() {
		int i = 0, j = -1; nxt[0] = -1;
		while (i != L)
		{
			if (!~j || a[i] == a[j]) nxt[++i] = ++j;
			else j = nxt[j];
		}
		return ;
	};
	GetNext();
	r.n = L; b.n = L;
	for (int i = 0; i <= L; i++)
		r.m[i][i] = 1;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < 62; j++)
		{
			int k = i;
			for (; k != -1; k = nxt[k])
				if (a[k] == j) break;
			++b.m[i][k + 1];
		}
	b.m[L][L] = 62;
	for (; n; b = b * b, n >>= 1) if (n & 1) r = r * b;
	int ans = 0;
	for (int i = 0; i < L; i++) fadd(ans, r.m[0][i]);
	printf("%d\n", ans);
	return 0;
}