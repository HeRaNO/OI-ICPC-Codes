#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, k;

void solve()
{
	scanf("%d%d", &n, &k);
	if (((n + 1) * n / 2) % n != k)
		return puts("-1"), void();
	if(k==0)
	{
		if(n%2==0)return puts("-1"), void();
		printf("%d ",n);
		for(int i=1;i<n-i;i++)printf("%d %d ",i,n-i);
		return;
	}
	printf("%d %d ", n, k);
	for (int i = 1; i < n-i; i++)
	{
		if(i==k)continue;
		printf("%d %d ",i,n-i);
	}
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}