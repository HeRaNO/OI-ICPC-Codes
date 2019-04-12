#include <bits/stdc++.h>
using namespace std;

int T,n,m,a,b,c,d,p,q;

inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&p,&q);
		int mx=p-c,my=q-d,nx=a-c,ny=b-d;
		if (mx>=0&&my>=0)
		{
			if (!(nx>=0&&ny>=0)){puts("NO");continue;}
		}
		else if (mx>=0&&my<=0)
		{
			if (!(nx>=0&&ny<=0)){puts("NO");continue;}
		}
		else if (mx<=0&&my<=0)
		{
			if (!(nx<=0&&ny<=0)){puts("NO");continue;}
		}
		else
		{
			if (!(nx<=0&&ny>=0)){puts("NO");continue;}
		}
		mx=abs(mx);my=abs(my);nx=abs(nx);ny=abs(ny);
		int t=gcd(mx,my);mx/=t;my/=t;
		t=gcd(nx,ny);nx/=t;ny/=t;
		if (mx==nx&&my==ny) puts("YES");
		else puts("NO");
	}
	return 0;
}
