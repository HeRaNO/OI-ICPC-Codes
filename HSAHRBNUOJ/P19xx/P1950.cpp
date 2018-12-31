#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int a[1000001];
int i, j, k;
int n, start, finish;
int minl = INT_MAX, maxl = -1;
int ans1, ans2;
int cou;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &start, &finish);
		for (j = start + 1; j <= finish; j++)
			a[j] = 1;
		if (minl > start + 1) minl = start + 1;
		if (maxl < finish) maxl = finish;
	}
	for (i = minl; i <= maxl; i++)
	{
		if (a[i] == a[i - 1])
			cou++;
		else
		{
			if (a[i - 1])
			{
				if (ans1 < cou)
					ans1 = cou;
			}
			else
			{
				if (ans2 < cou)
					ans2 = cou;
			}
			cou = 1;
		}
	}
	if (ans1 < cou)
		ans1 = cou;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
