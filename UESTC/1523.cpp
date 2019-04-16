#include <bits/stdc++.h>
using namespace std;

int n,m[4],x,y,z,p,q,r;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x!=i) m[++m[0]]=i;
	}
	if (!m[0]) puts("0");
	else if (m[0]==2) printf("%d\n",min(m[2]-m[1],n-m[2]+m[1])*2-1);
	else
	{
		x=min(m[2]-m[1],n-m[2]+m[1]);
		y=min(m[3]-m[1],n-m[3]+m[1]);
		z=min(m[3]-m[2],n-m[3]+m[2]);
		p=(x<<1)+(y<<1)-2;
		q=(y<<1)+(z<<1)-2;
		r=(x<<1)+(z<<1)-2;
		printf("%d\n",min(p,min(q,r)));
	}
	return 0;
}