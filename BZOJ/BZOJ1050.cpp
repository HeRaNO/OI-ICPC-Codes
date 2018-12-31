#include <cstdio>
#include <algorithm>
#define MAXN 510
#define MAXM 5010
using namespace std;

struct road
{
	int x;
	int y;
	int val;
};

road a[MAXM];
int father[MAXN];
int n, m;
int s, t;
int fz, fm;
int ansfz = 1, ansfm;
int start = 1;

inline void clear_father()
{
	for (int i = 1; i <= n; i++)
		father[i] = i;
}

bool cmp(road a, road b)
{
	return a.val < b.val;
}

int getfather(int x)
{
	return father[x] == x ? x : getfather(father[x]);
}

void merge(int x, int y)
{
	int fx = getfather(x);
	int fy = getfather(y);
	if (fx != fy) father[fx] = fy;
	return ;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].val);
	scanf("%d %d", &s, &t);
	sort(a + 1, a + m + 1, cmp);
	while (start <= m)
	{
		fz = fm = -1;
		int j;
		clear_father();
		for (j = start; j <= m; j++)
		{
			merge(a[j].x, a[j].y);
			if (getfather(s) == getfather(t))
			{
				fz = a[j].val;
				break;
			}
		}
		if (fz == -1)
		{
			if (!ansfm)
			{
				puts("IMPOSSIBLE");
				return 0;
			}
			else break;
		}
		clear_father();
		for (; j >= 1; j--)
		{
			merge(a[j].x, a[j].y);
			if (getfather(s) == getfather(t))
			{
				fm = a[j].val;
				break;
			}
		}
		start = j + 1;
		if (fm == -1)
		{
			if (!ansfm)
			{
				puts("IMPOSSIBLE");
				return 0;
			}
			else break;
		}
		int r = gcd(fz, fm);
		fz /= r;
		fm /= r;
		if (ansfz * fm > ansfm * fz)
		{
			ansfz = fz;
			ansfm = fm;
		}
	}
	int x = gcd(ansfz, ansfm);
	ansfz /= x;
	ansfm /= x;
	if (ansfm == 1) printf("%d\n", ansfz);
	else printf("%d/%d\n", ansfz, ansfm);
	return 0;
}