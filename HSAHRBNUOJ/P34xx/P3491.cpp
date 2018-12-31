#include <cstdio>
#include <cstring>
#define MAXNL 1010
#define MAXNS 110
#define LLMAX 9223372036854775807LL
using namespace std;

bool dp1[MAXNS][MAXNS], small, res;
int a[MAXNL], A, B, bit, n;
long long sum, ans;
int dp2[MAXNL];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline bool check_small(long long ans, long long t)
{
	memset(dp1, 0, sizeof dp1);
	dp1[0][0] = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= B; j++)
		{
			long long tt = a[i];
			for (int k = i - 1; ~k; k--)
			{
				if ((tt | ans) < t) dp1[i][j] = dp1[i][j] || dp1[k][j - 1];
				tt += a[k];
			}
		}
	for (int i = A; i <= B; i++) if (dp1[n][i]) return false;
	return true;
}

inline bool check_big(long long ans, long long t)
{
	memset(dp2, 0x7f, sizeof dp2);
	dp2[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		long long tt = a[i];
		for (int j = i - 1; ~j; j--)
		{
			if ((tt | ans) < t) dp2[i] = mymin(dp2[i], dp2[j] + 1);
			tt += a[j];
		}
	}
	if (dp2[n] != 0x7f7f7f && dp2[n] <= B) return false;
	else return true;
}

int main()
{
	scanf("%d %d %d", &n, &A, &B);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n <= 100) small = true;
	for (int i = 1; i <= n; i++) sum += +a[i];
	for (; sum >> bit; bit++);
	for (int i = bit; ~i; i--)
	{
		long long t = ans | (1LL << i);
		if (small) res = check_small(ans, t);
		else res = check_big(ans, t);
		if (res) ans |= (1LL << i);
	}
	printf("%lld\n", ans);
	return 0;
}
