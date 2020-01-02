#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const int d[8][2]={
	{0,1},{0,-1},{-1,0},{1,0},
	{1,1},{1,-1},{-1,1},{-1,-1}
};

set <pair<int,int> > mp;
int n,cnt[5],x[MAXN],y[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		mp.insert(make_pair(x[i],y[i]));
	}
	for (int i=1;i<=n;i++)
	{
		bool f=true;int sc=0;
		for (int j=0;j<4&&f;j++)
			if (mp.find(make_pair(x[i]+d[j][0],y[i]+d[j][1]))==mp.end())
				f=false;
		if (!f) continue;
		for (int j=4;j<8;j++)
			if (mp.find(make_pair(x[i]+d[j][0],y[i]+d[j][1]))!=mp.end())
				++sc;
		++cnt[sc];
	}
	for (int i=0;i<=4;i++) printf("%d\n",cnt[i]);
	return 0;
}