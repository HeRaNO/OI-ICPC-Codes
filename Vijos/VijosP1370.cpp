#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct fruit
{
	long num;
	long value;
	long time;
	long before;
};

long limitime, tree;
fruit a[101];
long treetime[101][101] = { 0 }, f[110][1010] = { 0 };
long i, j, k, maxl = 0;

long max(long x, long y)
{
	return x > y ? x : y;
}

int main()
{
	//freopen("fruit.in","r",stdin);
	//freopen("fruit.out","w",stdout);
	cin >> tree >> limitime;
	for (i = 1; i <= tree; i++)
	{
		scanf("%ld%ld%ld", &a[i].num, &a[i].value, &a[i].time);
		a[i].before = i;
	}
	for (i = 1; i <= tree; i++)
		for (j = 1; j <= tree; j++)
			scanf("%ld", &treetime[i][j]);
	for (i = 1; i <= tree - 1; i++)
		for (j = 1; j <= tree - i; j++)
		{
			if (a[j].num > a[j + 1].num)
				swap(a[j], a[j + 1]);
		}
	for (i = 1; i <= tree; i++)
		for (j = limitime; j >= 0 ; j--)
			for (k = i - 1; k >= 0; k--)
			{
				if (j - treetime[a[k].before][a[i].before] - a[i].time >= 0 && a[i].num > a[k].num)
				{
					f[i][j] = max(f[i][j], f[k][j - treetime[a[k].before][a[i].before] - a[i].time] + a[i].value);
					maxl = max(maxl, f[i][j]);
				}
			}
	cout << maxl;
	return 0;
}