//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 40
using namespace std;

double male[MAXN], female[MAXN], in;
char s[MAXN];
int cntmale, cntfemale, n;

bool cmpup(double a, double b)
{
	return a < b;
}

bool cmpdown(double a, double b)
{
	return a > b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s %lf", s, &in);
		if (s[0] == 'f') female[++cntfemale] = in;
		else male[++cntmale] = in;
	}
	sort(male + 1, male + cntmale + 1, cmpup);
	sort(female + 1, female + cntfemale + 1, cmpdown);
	for (int i = 1; i <= cntmale; i++)
		printf("%.2lf ", male[i]);
	for (int i = 1; i <= cntfemale; i++)
		printf("%.2lf ", female[i]);
	return 0;
}
