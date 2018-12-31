#include <cstdio>
#define mod 7654321

using namespace std;

int n;
int f[10005][5];

int main()
{
	scanf("%d", &n);
	f[1][1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		f[i][1] = f[i - 1][3] % mod;
		f[i][2] = f[i - 1][4] % mod;
		f[i][3] = (f[i - 1][1] + f[i - 1][4]) % mod;
		f[i][4] = (f[i - 1][2] + f[i - 1][3]) % mod;
	}
	printf("%d", (f[n][1] + f[n][2] + f[n][3] + f[n][4]) % mod);
	return 0;
}
