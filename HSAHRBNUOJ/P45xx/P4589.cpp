#include <cstdio>
#define MAXN 1010
using namespace std;

struct cheese
{
	long long x, y, z;
};

cheese a[MAXN];
int n, T, father[MAXN], fx, fy;
long long h, r;
bool f;

inline long long sqr(long long a)
{
	return a * a;
}

inline long long getdis(int i, int j)
{
	return sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y);
}

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

inline int read()
{
	int x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return f ? -x : x;
}

int main()
{
	//freopen("cheese.in","r",stdin);freopen("cheese.out","w",stdout);
	T = read();
	while (T--)
	{
		n = read();
		h = read();
		r = read();
		f = false;
		for (int i = 0; i <= n + 1; i++) father[i] = i;
		for (int i = 1; i <= n; i++)
		{
			a[i].x = read();
			a[i].y = read();
			a[i].z = read();
			if (a[i].z <= r && a[i].z >= -r)
			{
				fx = getfather(i);
				fy = getfather(0);
				if (fx != fy) father[fy] = fx;
			}
			if (a[i].z >= h - r && a[i].z <= h + r)
			{
				fx = getfather(i);
				fy = getfather(n + 1);
				if (fx != fy) father[fy] = fx;
			}
		}
		for (int i = 1; i <= n && !f; i++)
			for (int j = 1; j <= n && !f; j++)
			{
				if (getdis(i, j) <= 4 * r * r - sqr(a[i].z - a[j].z))
				{
					fx = getfather(i);
					fy = getfather(j);
					if (fx != fy) father[fy] = fx;
				}
				if (getfather(0) == getfather(n + 1))
				{
					f = true;
					puts("Yes");
				}
			}
		if (!f) puts("No");
	}
	return 0;
}
