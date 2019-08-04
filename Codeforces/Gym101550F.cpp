#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int p,n;
double ans;

int main()
{
	scanf("%d %d",&n,&p);
	ans=(double)p/(double)(n+1);
	double nxt=ans;
	for (int i=2;i<=n;i++)
	{
		nxt=(double)nxt*(double)(n-p+i)/(double)(n+i);
		if (i*nxt>ans) ans=nxt*i;
	}
	printf("%.12lf\n",ans);
	return 0;
}