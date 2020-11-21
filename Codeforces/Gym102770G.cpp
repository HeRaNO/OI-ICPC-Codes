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
const int N = 4050;
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
int n, sx, sy, tx, ty;
double vh, vp, vf;
struct windcave
{
	int x, y;
	double v;
} a[N];

double dis[N];
inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / vh;
}
bool vis[N];
void dijkstra(int s)
{
	for (int i = 1; i <= n + 5; ++i)
		dis[i] = llinf,vis[i]=0;
	dis[s] = 0;
	for(int kase=1;kase<=n;kase++)
	{
		int u=n+1;
		for(int i=1;i<=n;i++)if(!vis[i])
		{
			if(dis[i]<dis[u])u=i;
		}
		vis[u]=1;
		for (int i = 1; i <= n; ++i)
		{
			if (vp - a[i].v >= 0)
				continue;
			double nowdis = dist(a[u].x, a[u].y, a[i].x, a[i].y);
			nowdis += nowdis * vp / (a[i].v-vp);
			if (dis[i] > dis[u] + nowdis)
			{
				dis[i] = dis[u] + nowdis;
			}
		}
	}
}

int VF, VP, VH;
inline void solve()
{
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	scanf("%d%d%d",&VF,&VP,&VH);

	vf = VF, vp = VP, vh = VH;
	scanf("%d",&n);
	for (int i = 1; i <= n + 1; ++i)
	{
		int v;
		scanf("%d%d%d",&a[i].x,&a[i].y,&v);
		a[i].v = v;
	}
	n += 2;
	a[n].x = tx, a[n].y = ty, a[n].v = 0;
	dijkstra(n);
	double ans = dis[1];
	printf("%.12lf\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
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