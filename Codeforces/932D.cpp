#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=400050;
int Q,cnt=1;
int p[N][20];
int p2[N][20];
ll mx[N][20];
ll sum[N][20];
ll w[N];
ll las;
ll ans;

int main()
{
	cin>>Q;
	while(Q--)
	{
		int op,R,W;ll X;
		scanf("%d",&op);
		if(op==1)
		{
			cnt++;
			scanf("%d%d",&R,&W);R^=las;W^=las;
			p[cnt][0]=R;w[cnt]=W;mx[cnt][0]=W;sum[cnt][0]=W;
			for(int i=1;i<20;++i)
			{
				p[cnt][i]=p[p[cnt][i-1]][i-1];
				mx[cnt][i]=max(mx[cnt][i-1],mx[p[cnt][i-1]][i-1]);
			}
			int pos=p[cnt][0];
			for(int i=19;~i;--i)if(mx[pos][i]<w[cnt])pos=p[pos][i];
			p2[cnt][0]=pos;
			for(int i=1;i<20;++i)
			{
				p2[cnt][i]=p2[p2[cnt][i-1]][i-1];
				sum[cnt][i]=sum[cnt][i-1]+sum[p2[cnt][i-1]][i-1];
			}
		}
		else
		{
			scanf("%d%lld",&R,&X);R^=las;X^=las;
			ans=0;
			int pos=R;
			for(int i=19;~i;--i)
			{
				if(p2[pos][i]&&X>=sum[pos][i])
				{
					X-=sum[pos][i];
					ans+=(1<<i);
					pos=p2[pos][i];
				}
			}
			if(X>=sum[pos][0])ans++;
			printf("%lld\n",ans);
			las=ans;
		}
	}
	return 0;
}
