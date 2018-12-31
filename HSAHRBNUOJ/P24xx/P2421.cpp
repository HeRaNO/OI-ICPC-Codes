#include <cmath>
#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

struct point
{
	double x;
	double y;
};

struct person
{
	double x;
	double y;
	double v;
};

point pass[MAXN];
person pos[MAXN];
int r, a;
double t;
int road[MAXN][MAXN];
bool state[MAXN];
int result[MAXN];
int ans;

bool Hungary(int x)
{
	for (int i = 1; i <= road[x][0]; i++)
	{
		if (state[road[x][i]]) continue;
		state[road[x][i]] = true;
		if (!result[road[x][i]] || Hungary(result[road[x][i]]))
		{
			result[road[x][i]] = x;
			return true;
		}
	}
	return false;
}

double get_length(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
	//freopen("input4.txt","r",stdin);
	scanf("%d %d %lf", &r, &a, &t);
	for (int i = 1; i <= a; i++)
		scanf("%lf %lf", &pass[i].x, &pass[i].y);
	for (int i = 1; i <= r; i++)
		scanf("%lf %lf %lf", &pos[i].x, &pos[i].y, &pos[i].v);
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= r; j++)
		{
			if (get_length(pass[i].x, pass[i].y, pos[j].x, pos[j].y) - pos[j].v * t <= 0)
				road[j][++road[j][0]] = i;
		}
	for (int i = 1; i <= r; i++)
	{
		memset(state, false, sizeof(state));
		if (Hungary(i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
