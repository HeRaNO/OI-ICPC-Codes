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
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) v.begin(), v.end()
#define vecupsort(v) (sort(v.begin(), v.end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
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
int m, n;
priority_queue<int> q;

void solve()
{
	scanf("%d%d", &n, &m);
	if (n < m)
		swap(n, m);
	int delta = n % m;
	if (delta == 0)
	{
		printf("%d\n", n);
		for (int i = 1; i <= n; ++i)
			printf("%d ", m);
		puts("");
		return;
	}
	while (n && m)
	{
		if (delta == 0)
		{
			for (int i = 1; i <= n; ++i)
				q.push(m);
			break;
		}
		int ans = inf;
		int ansk = 0;
		for (int k = 0; k < n; ++k)
		{
			int tmp = 0;
			if (k * m * (n / m) >= delta * (n - k))
			{
				tmp = n - k;
				tmp += (k * m) / (delta);
				if (k * m % (delta) != 0)
					tmp++;
				if (ans > tmp)
				{
					ansk = k;
					ans = tmp;
				}
			}
		}
		for (int i = 1; i <= n - ansk; ++i)
			q.push(m);
		n = ansk * m / delta, m = delta;
		delta = n % m;
	}
	// int sum = 0;
	// for (int i = 1; i <= n - ansk; ++i)
	//     q.push(m), sum += m;
	// for (int i = 1; i <= ansk * m / (delta); ++i)
	//     q.push(delta), sum += delta;
	// if (sum - n * m < 0)
	//     q.push(n * m - sum);
	cout << q.size() << '\n';
	while (!q.empty())
		printf("%d ", q.top()), q.pop();
	puts("");
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}