#include <bits/stdc++.h>
using namespace std;

int y,m,d,a,b,c,T,q;
char x[100];
long long de;

char week[10][10]={
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday"
};

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %s",&y,&m,&d,x);
		if (x[0]=='M') q=0;
		else if (x[0]=='T'&&x[1]=='u') q=1;
		else if (x[0]=='W') q=2;
		else if (x[0]=='T'&&x[1]=='h') q=3;
		else q=4;
		scanf("%d %d %d",&a,&b,&c);
		if (y==a)
		{
			if (make_pair(m,d)<make_pair(b,c))
			{
				while (make_pair(m,d)!=make_pair(b,c))
				{
					++d;++q;if (q==5) q=0;
					if (d==31){++m;d=1;}
				}
			}
			else
			{
				while (make_pair(m,d)!=make_pair(b,c))
				{
					++c;--q;if (q==-1) q=5;
					if (c==31){++b;c=1;}
				}
			}
			puts(week[q]);
		}
		else
		{
			if (make_pair(make_pair(y,m),d)<make_pair(make_pair(a,b),c))
			{
				de=30-d;
				de+=c;
				puts(week[(de+q)%5]);
			}
			else
			{
				de=30-c;
				de+=d;
				for (int i=0;i<5;i++)
				{
					if ((i+de)%5==q)
					{
						puts(week[i]);break;
					}
				}
			}
		}
	}
	return 0;
}