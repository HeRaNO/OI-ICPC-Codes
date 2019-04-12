#include <cstdio>

long long x[4],y[4];
int T,cnt;

long long len(int tag)
{
	if (tag==1)
		return (x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]);
	else if (tag==0)
		return (x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]);
	else if (tag==2)
		return (x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
	else
		return (x[3]-x[0])*(x[3]-x[0])+(y[3]-y[0])*(y[3]-y[0]);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		printf("Case #%d: ",++cnt);
		for (int i=0;i<4;i++) scanf("%lld %lld",&x[i],&y[i]);
		if ((x[1]-x[0])*(y[3]-y[2])==(y[1]-y[0])*(x[3]-x[2]))
		{
			if (len(1)!=len(0)) puts("Others");
			else
			{
				if ((x[1]-x[0])*(x[2]-x[1])+(y[1]-y[0])*(y[2]-y[1])==0)
				{
					if (len(0)==len(3)) puts("Square");
					else puts("Rectangle");
				}
				else if ((x[2]-x[0])*(x[3]-x[1])+(y[2]-y[0])*(y[3]-y[1])==0)
				{
					if (len(0)==len(1)&&len(1)==len(2)&&len(2)==len(3)) puts("Diamond");
					else puts("Others");
				}
				else puts("Parallelogram");
			}
		}
		else puts("Others");
	}
	return 0;
}
