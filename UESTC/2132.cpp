#include <bits/stdc++.h>
using namespace std;

const int mm[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31},
};

int y,m,d,a,b,cnt,T;

int f(int x)
{
	if (!(x%100))
	{
		if (x%400) return 0;
		else return 1;
	}
	if (x%4) return 0;
	return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt=0;
		scanf("%d %d %d %d %d",&y,&m,&d,&a,&b);
		while (true)
		{
			if (m==a&&b==d) break;
			++cnt;++d;
			if (d>mm[f(y)][m])
			{
				d=1;++m;
			}
			if (m>12)
			{
				++y;m=1;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}