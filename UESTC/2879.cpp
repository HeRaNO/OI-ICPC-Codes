#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

const int N=10000;

struct pcr
{
	int x,y,z;
	pcr(){}
	pcr(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
	void print()
	{
		if (!x&&!y&&!z) puts("-1");
		else printf("%d %d %d\n",x,y,z);
		return ;
	}
	bool empty()
	{
		return !x&&!y&&!z;
	}
};

pcr a[MAXN];

int main()
{
	for (int i=0;8*i<=N;i++)
		for (int j=0;8*i+9*j<=N;j++)
			for (int k=0;8*i+9*j+10*k<=N;k++)
				if (a[8*i+9*j+10*k].empty())
					a[8*i+9*j+10*k]=pcr(i,j,k);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		a[n].print();
	}
	return 0;
}