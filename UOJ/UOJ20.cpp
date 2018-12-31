#include <cstdio>
#include <cstring>
#define MAXN 105
#define MAXL 10010
using namespace std;

const int mod[] = {17707, 17713, 17729, 20323, 20327};
const int T = 5;

int n, m, l;
int a[5][MAXN], f[5][21000], ans[1000010];
char s[MAXL];

inline int CalcF(int w, int x)
{
	int ans = a[w][n];
	for (int i = n - 1; ~i; i--) ans = (ans * x + a[w][i]) % mod[w];
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		scanf("%s", s);
		l = strlen(s);
		if (s[0] == '-')
		{
			for (int j = 0; j < T; j++)
			{
				for (int k = 1; k < l; k++) a[j][i] = (a[j][i] * 10 + s[k] - '0') % mod[j];
				a[j][i] = (mod[j] - a[j][i]) % mod[j];
			}
		}
		else
		{
			for (int j = 0; j < T; j++)
				for (int k = 0; k < l; k++)
					a[j][i] = (a[j][i] * 10 + s[k] - '0') % mod[j];
		}
	}
	for (int j = 0; j < T; j++)
		for (int i = 0; i < mod[j]; i++)
			f[j][i] = CalcF(j, i);
	for (int i = 1; i <= m; i++)
	{
		bool sol = true;
		for (int j = 0; j < T && sol; j++) if (f[j][i % mod[j]]) sol = false;
		if (sol) ans[++ans[0]] = i;
	}
	for (int i = 0; i <= ans[0]; i++) printf("%d\n", ans[i]);
	return 0;
}