#include <cstdio>
#define MAXN 1000005
using namespace std;

int n,m,o,x;

struct Queue
{
	int a[MAXN],q[MAXN],n,l,r;
	Queue(){l=1;r=0;n=0;}
	void push(int x)
	{
		a[++n]=x;
		while (l<=r&&q[l]+m<=n)  ++l;
		while (l<=r&&a[q[r]]<=x) --r;
		q[++r]=n;
		return ;
	}
	int front(){return a[q[l]];}
};

Queue mx,mn;

int main()
{
	scanf("%d %d",&n,&m);
	while (n--)
	{
		scanf("%d",&o);
		if (o==1)
		{
			scanf("%d",&x);
			mx.push(x);mn.push(-x);
		}
		else
		{
			int ans=mx.front()-mn.front();
			if (ans&1) printf("%d.5\n",ans>>1);
			else printf("%d.0\n",ans>>1);
		}
	}
	return 0;
}