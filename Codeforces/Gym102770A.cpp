#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 5000050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
// int sum[90000000];
const int offset = 20000100;
char s[10];
const int SIZ = 10000000 + 3;
char buf1[SIZ];
char *p1 = buf1, *p2 = buf1;
inline char readchar()
{
	if (p1 == p2)
		p1 = buf1, p2 = buf1 + fread(buf1, 1, SIZ, stdin);
	return p1 == p2 ? EOF : *p1++;
}
inline int read()
{
	int ret, c;
	while ((c = readchar()) > '9' || c < '0')
		;
	ret = c - '0';
	while ((c = readchar()) >= '0' && c <= '9')
		ret = ret * 10 + c - '0';
	return ret;
}

inline bool check()
{
	for (int i = 0; i <= 5; ++i)
	{
		if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2')
			return 1;
	}
	return 0;
}
int q[N], cnt;
int Day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline bool isrun(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return 1;
	return 0;
}

void Init()
{
	for (int i = 2000; i <= 9999; ++i)
	{
		for (int month = 1; month <= 12; ++month)
		{
			bool isrunnian = 0;
			if (isrun(i))
				// Day[2]++;
				isrunnian = 1, Day[2]++;
			for (int k = 1; k <= Day[month]; ++k)
			{
				int year = 10000 * i + month * 100 + k;
				memarray(s, 0);
				sprintf(s, "%d", year);
				// sum[i - offset] = sum[i - offset - 1] + check();
				if (check())
				{
					q[++cnt] = year;
				}
			}
			if(isrunnian)
				Day[2]--;
		}
	}

	q[++cnt] = 1000000000;
}

inline void solve()
{
	int YY = read(), MM = read(), DD = read(), yy = read(), mm = read(), dd = read();
	int l = YY * 10000 + MM * 100 + DD;
	int r = yy * 10000 + mm * 100 + dd;
	l = lower_bound(q + 1, q + cnt + 1, l) - q;
	r = upper_bound(q + 1, q + cnt + 1, r) - q - 1;
	printf("%d\n", r - l + 1);
}

int main()
{
	TIME__START = clock();
	Init();
	int Test = 1;
	// scanf("%d", &Test);
	Test = read();
	while (Test--)
	{
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}