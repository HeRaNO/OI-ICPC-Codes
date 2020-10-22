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
const int N = 300050;
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

long long n, d[N], m;
int endpos[N];
char s[N];
int ch[N][30],cnt;
long long ans[N], val[N],res[N];
int pval[N];

void insert_Trie(int p)
{
	int u = 0,n=strlen(s);
	for (int i = 0; i < n;i++)
	{
		if(!ch[u][s[i]-'a'])
			ch[u][s[i] - 'a'] = ++cnt,pval[cnt]=s[i]-'a';
		u = ch[u][s[i] - 'a'];
		val[u]++;
	}
	endpos[p] = u;
}

vector<int> v[N];

void bfs()
{
	for (int i = 1; i <= cnt;i++)
		ans[i] = d[pval[i]];
	for (int i = 1; i <= cnt; i++)
		 for (int j = 0; j < 26; j++)
			 if (ch[i][j])
			ans[ch[i][j]] = (ans[ch[i][j]] * ans[i]) % m;
	for (int i = 1; i <= cnt;i++)
		v[ans[i]].pb(i);
}

int in[N],out[N], tot;
struct BIT
{
	long long a[N];
	int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x,int val)
	{
		while(x<=tot+5)
		{
			a[x] += val;
			x += lowbit(x);
		}
	}
	long long query(int x)
	{
		long long ans = 0;
		while(x)
		{
			(ans += a[x]);
			x -= lowbit(x);
		}
		return ans;
	}
} B;

void dfs(int u)
{
	in[u]=++tot;
	for (int i = 0; i < 26;i++)if(ch[u][i])
			dfs(ch[u][i]);
	out[u] = tot;
}

inline void solve()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < 26;i++)
		scanf("%lld", &d[i]),d[i]%=m;
	for (int i = 1; i <= n;i++)
	{
		scanf("%s", s);
		insert_Trie(i);
	}
	bfs();
	dfs(0);
	for (int i = 0; i<m;i++)
	{
		for(auto j:v[i])
			B.add(in[j], val[j]), B.add(out[j]+1, -val[j]);
		for(auto j:v[i])
		{
			long long tmp = B.query(in[j]);
			B.add(in[j], -tmp);
			B.add(in[j] + 1, tmp);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", B.query(in[endpos[i]]));
	}
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	//scanf("%d", &Test);
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