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
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n;
ll vis[1000006];
ll pri[1000005];
ll tot;
vector<pii> ans;
// bool vis[N];
void pre()
{
	for (int i = 2; i <= 1000000; ++i)
	{
		if (!vis[i])
			vis[i] = i, pri[++tot] = i;
		for (int j = 1; j <= tot && i * pri[j] <= 1000000; ++j)
		{
			vis[i * pri[j]] = pri[j];
			if (i % pri[j] == 0)
				break;
		}
	}
}
int b[N];
int a[N];
bool vis2[N];
vector<int> vec[N];
set<int> s;
bool cmp(const int &x, const int &y)
{
	return vis[x] < vis[y];
}

void solve()
{
	ans.clear();
	s.clear();
	mem(vis2, 0, n, bool);
	mem(a, 0, n, int);
	scanf("%d", &n);
	for (int i = 1; pri[i] <= n; ++i)
		vec[pri[i]].clear();
	for (int i = 2; i <= n; ++i)
		vec[vis[i]].push_back(i), s.insert(i);
	// mem(vis, 0, n, bool);
	int nowtot = 1;
	int cnt = 0;
	while (true)
	{
		int now = pri[nowtot];
		if (now > n / 2)
			break;
		if (!vec[now].size())
			break;
		for (int i = vec[now].size() - 1; i - 1 >= 0; i -= 2)
		{
			// cout << vec[now][i] << '\n';
			a[vec[now][i]] = vec[now][i - 1];
			a[vec[now][i - 1]] = vec[now][i];
			s.erase(vec[now][i]), s.erase(vec[now][i - 1]);
			vis2[vec[now][i]]=1;vis2[vec[now][i - 1]]=1;
		}
		nowtot++;
	}
	vector<int> tmp;
	for (auto i : s)
	{
		b[vis[i]] = i;
		tmp.push_back(i);
	}
	sort(tmp.begin(), tmp.end());
	stack<int> ssss;
	for(auto u:tmp)
	{
		int v = u*2;
		//if(u==2)continue;
		if(v>n)break;
		ssss.push(a[v]);
		a[u] = v, a[v] = u;
		if(ssss.size()>1)
		{
			int u=ssss.top();ssss.pop();
			int v=ssss.top();ssss.pop();
			a[u]=v;
			a[v]=u;
		}
	}
	mem(vis2, 0, n, bool);
	for (int i = 2; i <= n; ++i)
	{
		if (!vis2[i] && !vis2[a[i]] && a[i])
		{
			ans.push_back(mp(i, a[i]));
			vis2[i] = vis2[a[i]] = 1;
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
	{
		printf("%d %d\n", i.first, i.second);
	}
}

int main()
{
	TIME_START = clock();
	pre();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}