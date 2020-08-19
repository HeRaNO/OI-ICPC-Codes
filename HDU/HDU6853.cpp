#include <bits/stdc++.h>
using namespace std;

const int d[8][2]={
	{-1,0},{1,0},{0,-1},{0,1},
	{-1,-1},{1,-1},{-1,1},{1,1}
};

set <pair<long long,long long> > s;
queue <pair<long long,long long> > q;

inline bool check(long long nx,long long ny)
{
	return __gcd(nx,ny)!=1&&!s.count({nx,ny});
}

inline void Solve()
{
	long long x,y,ansx=1,ansy=0;
	scanf("%lld %lld",&x,&y);
	while (!q.empty()) q.pop();
	q.push({x,y});s.clear();s.insert({x,y});
	while (!q.empty())
	{
		int cnt=1;
		pair<long long,long long> u=q.front();q.pop();
		if (u.first==u.second) return puts("0/1"),void();
		for (int i=0;i<8;i++)
		{
			long long nx=u.first+d[i][0],ny=u.second+d[i][1];
			if (__gcd(nx,ny)!=1)
			{
				++cnt;
				if (!s.count({nx,ny}))
				{
					q.push({nx,ny});s.insert({nx,ny});
				}
			}
		}
		ansy+=cnt;
	}
	for (int i=0;i<8;i++)
		if (__gcd(x+d[i][0],y+d[i][1])!=1) ++ansx;
	//printf("%lld %lld\n",ansx,ansy);
	long long d=__gcd(ansx,ansy);
	printf("%lld/%lld\n",ansx/d,ansy/d);
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}