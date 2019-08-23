#include <bits/stdc++.h>
using namespace std;

int T;
unsigned int a,b,c;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%u %u",&a,&b);c=0;
		for (int i=0;i<32;i++)
			if ((a&(1<<i))&&(b&(1<<i)))
				c|=(1<<i);
		if (!c)
		{
			int p=0,q=0;
			for (int i=0;i<32&&!p;i++) if (a&(1<<i)) p=i;
			for (int i=0;i<32&&!q;i++) if (b&(1<<i)) q=i;
			c=1<<min(p,q);
		}
		printf("%u\n",c);
	}
	return 0;
}