#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);

int T,n,R,x,y,r;
double ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&R);ans=2*pi*R;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&x,&y,&r);
			int dis=x*x+y*y;
			if ((R-r)*(R-r)<=dis&&dis<(R+r)*(R+r))
			{
				if (dis==(R-r)*(R-r)) ans+=2*pi*r;
				else
				{
					double d=sqrt(dis);
					double alpha=2*acos((d*d+R*R-r*r)/(2*d*R));
					ans-=R*alpha;
					double beta=2*acos((d*d+r*r-R*R)/(2*d*r));
					ans+=r*beta;
				}
				
			}
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}