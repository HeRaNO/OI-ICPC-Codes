#include <cstdio>
#define MAXN 100010
using namespace std;

struct explo
{
	bool type;
	int a;
};

int n, w, u;
double k, c, p, q, t;
explo x[MAXN];

inline double mymax(double a, double b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("explo.in","r",stdin);freopen("explo.out","w",stdout);
	scanf("%d %lf %lf %d", &n, &k, &c, &w);
	p = 1.0 - 0.01 * k;
	q = 1.0 + 0.01 * c;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &u, &x[i].a);
		x[i].type = --u;
	}
	for (int i = n; i; i--)
	{
		if (x[i].type) t = mymax(t, t * q - (double)x[i].a);
		else t = mymax(t, t * p + (double)x[i].a);
	}
	printf("%.2lf\n", t * (double)w);
	return 0;
}
