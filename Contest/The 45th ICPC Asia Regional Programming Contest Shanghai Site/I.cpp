#include <bits/stdc++.h>
using namespace std;
int n, m;
double ans;
const double pi = acos(-1.0);

int main()
{
	scanf("%d%d", &n, &m);
	if (m > 1)
		ans += m * n * (n + 1);
	double res1 = 0;
	for (int i = 1; i <= n; ++i)
	{
		double res2 = 0;
		for (int j = 0; j < m; ++j)
		{
			double res3 = 0;
			double ang = pi * j / m;
			// ang = min(ang, 2 * pi - ang);
			for (int k = 1; k < i; ++k)
			{
				double mn = ang * k + i - k;
				mn = min(mn, 1.0 * i + k);
				res3 += mn;
			}
			for (int k = i; k <= n; ++k)
			{
				double mn = ang * i + k - i;
				mn = min(mn, 1.0 * i + k);
				res3 += mn;
			}
			res2 += res3;
		}
		res1 += res2 * 2;
		//for (int k = 1; k <= n; ++k)
			//res1 += i + k;
		//res1 += n * i;
		//res1 += n * (n + 1) / 2;
		//for (int k = 1; k <= n; ++k)
			//res1 -= abs(i - k);
		res1 -= i * (i - 1) / 2;
		res1 -= (n - i + 1) * (n - i) / 2;
	}
	ans += (res1 + n * n * (n + 1))  * m;
	//ans += ;
	printf("%.12lf\n", ans);
#ifdef ONLINE
	system("pause");
#endif
	return 0;
}